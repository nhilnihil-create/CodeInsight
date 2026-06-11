#include <bits/stdc++.h>
 
#define rep(i, n) for (ll i=0;i<(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(x) (x).begin(),(x).end()
 
using namespace std;
//using ll=long long;
typedef long long ll;
typedef pair<ll, ll> pi;
 
 
 
int main(){
  ll n,k;

  cin >> n;

  string s;

  cin >> s;
  vector<ll> S(n+1);
  vector<ll> A(n+1);
  S[0] = 0;
  
  rep(i,n){
    if(s[i]=='#') S[i+1]=1;
    S[i+1]+=S[i];
  }

  ll ans = min(S[n], n-S[n]);
  ll tmp = 0;
  rep(i,n){
    tmp = S[i+1];
    // left kuro
    tmp += n - (i+1) - S[n] + S[i+1];
    // right shiro
    ans = min(ans, tmp);
      }  
  
  cout << ans <<endl;
  
}
