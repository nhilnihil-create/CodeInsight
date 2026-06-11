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
map<ll,ll> ma;
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int main(){
  ll n; cin >> n;
  if(n==0){
    cout << 0 << endl;
    return 0;
  }
  string s="";
  while(n!=0){
    int k = n%2;
    if(k<0) k+=2;
    s += (char)('0' + k);
    n = (n-k)/(-2);
  }
  reverse(all(s));
  cout << s << endl;
  return 0;
}
