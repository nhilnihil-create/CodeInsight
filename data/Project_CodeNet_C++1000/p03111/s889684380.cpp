#include <iostream>
#include <vector>

using namespace std;

int n;
int a, b, c;
vector<int> l;

int ans = 10000;

void dfs(int i, int mp_a, int mp_b, int mp_c, int len_a, int len_b, int len_c) {
  if (len_a != 0 && len_b != 0 && len_c != 0) {
    int sum = abs(a - len_a) + abs(b - len_b) + abs(c - len_c);
    sum += (mp_a + mp_b + mp_c);
    ans = min(ans, sum);
    // cout << len_a << " " << len_b << " " << len_c << " " << sum << endl;
  }
  if (i == n) {
    return;
  }
  // i本目の竹をAとして使う
  if (len_a == 0) {
    dfs(i + 1, mp_a, mp_b, mp_c, len_a + l[i], len_b, len_c);
  } else {
    dfs(i + 1, mp_a + 10, mp_b, mp_c, len_a + l[i], len_b, len_c);
  }
  // i本目の竹をBとして使う
  if (len_b == 0) {
    dfs(i + 1, mp_a, mp_b, mp_c, len_a, len_b + l[i], len_c);
  } else {
    dfs(i + 1, mp_a, mp_b + 10, mp_c, len_a, len_b + l[i], len_c);
  }
  // i本目の竹をCとして使う
  if (len_c == 0) {
    dfs(i + 1, mp_a, mp_b, mp_c, len_a, len_b, len_c + l[i]);
  } else {
    dfs(i + 1, mp_a, mp_b, mp_c + 10, len_a, len_b, len_c + l[i]);
  }
  // i本目の竹を使わない
  dfs(i + 1, mp_a, mp_b, mp_c, len_a, len_b, len_c);
}

int main() {
  cin >> n >> a >> b >> c;
  l.assign(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  dfs(0, 0, 0, 0, 0, 0, 0);
  cout << ans << endl;

  return 0;
}