#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll n, a, b;
  cin>>n>>a>>b;
  vl p(n);
  ll que1 = 0;
  ll que2 = 0;
  ll que3 = 0;
  rep(i,n){
    cin >> p[i];
    if (p[i] <= a){
      que1++;
    }
    else if(p[i]<=b){
      que2++;
    }
    else{
      que3++;
    }
  }
  ll ans = min(que1, min(que2, que3));
  print(ans);
}