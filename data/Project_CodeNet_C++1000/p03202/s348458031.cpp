#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef long double db;
typedef long long ll;
template <typename tp>
inline void read(tp& x) {
  x = 0; char tmp; bool key = 0;
  for (tmp = gc(); !isdigit(tmp); tmp = gc())
    key = (tmp == '-');
  for (; isdigit(tmp); tmp = gc())
    x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
template <typename tp>
inline void ckmn(tp& x,tp y) {
  x = x < y ? x : y;
}
template <typename tp>
inline void ckmx(tp& x,tp y) {
  x = x < y ? y : x;
}

const int N = 200010;
int len[N], n, ans;
map<int,int> mp;
bool check(int x) {
  mp.clear();
  rep (i, 1, n) {
    if (len[i] > len[i-1]) continue;
    int p = len[i];
    while (p >= 1 && mp[p] == x-1) -- p;
    if (p == 0) return false;
    ++ mp[p];
    map<int,int> :: iterator it = mp.find(p);
    ++ it;
    mp.erase(it, mp.end());
  }
  return true;
}
int main() {
  read(n);
  rep (i, 1, n) read(len[i]);
  int key = 1;
  rep (i, 2, n) if (len[i] <= len[i-1]) key = 0;
  if (key)
    return puts("1"), 0;
  int l = 2, r = n, ans = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
