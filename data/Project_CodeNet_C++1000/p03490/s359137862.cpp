#include <cstdio>
#include <algorithm>
#include <vector>

const int MAXN = 8004;

char S[MAXN];
bool dx[MAXN], dx2[MAXN];
bool dy[MAXN], dy2[MAXN];

int iabs(int x) {
  return (x>=0 ? x : -x);
}

int main() {
  int X, Y;
  std::vector<int> xx, yy;
  fgets(S, MAXN, stdin);
  scanf("%d%d", &X, &Y);

  int i, cnt = 0;
  bool isY = false;
  for (i = 0; S[i] == 'F'; ++i) --X;
  for (; S[i]; ++i) {
    switch(S[i]) {
    case 'T':
      if (cnt > 0) {
        if (isY) yy.push_back(cnt);
        else xx.push_back(cnt);
      }
      cnt = 0;
      isY = !isY;
      break;
    case 'F':
      ++cnt;
    }
  }
  if (cnt > 0) {
    if (isY) yy.push_back(cnt);
    else xx.push_back(cnt);
  }

  // 이제 xx와 yy 각각의 덧셈과 뺄셈으로 x, y를 만들 수 있는지 확인하자.
  dx[0] = true;
  dy[0] = true;
  for (const auto &x: xx) {
    for (int i = 0; i < MAXN; ++i) {
      if (dx[i]) {
        dx2[iabs(i - x)] = dx2[iabs(i + x)] = true;
      }
    }
    std::copy(dx2, dx2 + MAXN, dx);
    std::fill(dx2, dx2 + MAXN, false);
  }
  for (const auto &y: yy) {
    for (int i = 0; i < MAXN; ++i) {
      if (dy[i]) {
        dy2[iabs(i - y)] = dy2[iabs(i + y)] = true;
      }
    }
    std::copy(dy2, dy2 + MAXN, dy);
    std::fill(dy2, dy2 + MAXN, false);
  }

  if (iabs(X) >= MAXN || iabs(Y) >= MAXN) puts("No");
  else if (dx[iabs(X)] && dy[iabs(Y)]) puts("Yes");
  else puts("No");

  return 0;
}
