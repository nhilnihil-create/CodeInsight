
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef struct s_t {
  int x;
  int y;
} s_t;

int main()
{
  int h, w, d;
  cin >> h >> w >> d;
  vector<s_t> s(h*w + 1);

  rep(i, h) {
    rep(j, w) {
      int tmp;
      cin >> tmp;
      s[tmp].x = i+1;
      s[tmp].y = j+1;
    }
  }

  vector<ll> rui(h*w + 1, 0);
  //  for (int i = 1; i <= d; i++) {
  //    rui[i] = 0;
  //    for (int j = i+d; j <= h*w; j += d) {
  //      rui[j] = rui[j-d] + abs(s[j-d].x - s[j].x) + abs(s[j-d].y - s[j].y);
  //    }
  //  }
  for (int i = d+1; i <= h*w; i++) {
    rui[i] = rui[i-d] + abs(s[i].x - s[i-d].x) + abs(s[i].y - s[i-d].y);
  }

  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    cout << rui[r] - rui[l] << endl;
  }
}
