#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int main(){
  int n;  cin >> n;
  string s[n];
  rep(i,0,n){
    cin >> s[i];
  }
  int cnta=0, cntb=0, k=0;
  rep(i,0,n){
    if(s[i][0]=='B'&&s[i].back()=='A') k++;
    else if(s[i][0]=='B') cntb++;
    else if(s[i].back()=='A') cnta++;
  }
  int cntab = 0;
  rep(i,0,n){
    rep(j,0,s[i].size()-1){
      if(s[i][j]=='A'&&s[i][j+1]=='B') cntab++;
    }
  }
  int ans = 0;
  if(cnta==0 && cntb==0){
    ans = max(0, k-1) + cntab;
  }else{
    ans = min(cnta, cntb) + cntab + k;
  }
  cout << ans << endl;
  return 0;
}
