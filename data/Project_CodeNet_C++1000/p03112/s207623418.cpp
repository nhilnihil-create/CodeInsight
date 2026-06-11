#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  const ll LINF = 1001001001001001;
  int a,b,q; cin >> a >> b >> q;
  vector<ll> s(a),t(b);
  rep(i,a) cin >> s[i];
  rep(i,b) cin >> t[i];
  rep(i,q){
    ll x; cin >> x;
    ll ans = LINF;
    ll temple1 = LINF, temple2 = LINF, shrine1 = LINF, shrine2 = LINF;
    int point1 = upper_bound(all(s),x) - s.begin();
    int point2 = upper_bound(all(t),x) - t.begin();
    if(point1 != 0) shrine1 = s[point1-1];
    if(point1 != s.size()) shrine2 = s[point1];
    if(point2 != 0) temple1 = t[point2-1];
    if(point2 != t.size()) temple2 = t[point2];
    chmin(ans,abs(x-temple1)+abs(temple1-shrine1));
    chmin(ans,abs(x-temple1)+abs(temple1-shrine2));
    chmin(ans,abs(x-temple2)+abs(temple2-shrine1));
    chmin(ans,abs(x-temple2)+abs(temple2-shrine2));
    chmin(ans,abs(x-shrine1)+abs(shrine1-temple1));
    chmin(ans,abs(x-shrine1)+abs(shrine1-temple2));
    chmin(ans,abs(x-shrine2)+abs(shrine2-temple1));
    chmin(ans,abs(x-shrine2)+abs(shrine2-temple2));
    cout << ans << endl;
  }
  // cout << "\n";
  return 0;
}
