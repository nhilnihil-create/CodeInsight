#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1<<30;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
int main(){
  int n;  cin >> n;
  string s; cin >> s;
  vector<int> wh(n+1,0),bl(n+1,0);
  rep(i,0,n){
    wh[i+1] = wh[i] + (s[i]=='.' ? 1 : 0);
    bl[i+1] = bl[i] + (s[i]=='#' ? 1 : 0);
  }
  ll res = 1LL<<60;
  for(int left=0 ; left<=n ; left++){
    ll tmp = 0;
    tmp += bl[left];
    tmp += wh[n] - wh[left];
    chmin(res, tmp);
  }
  cout << res << endl;
  return 0;
}
