#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int n;
  cin >>n;
  ll a[n];
  rep(i,n)cin >> a[i];
  ll l[n],r[n];
  ll ans=0;
  for(int i=0;i<n;i++){
    if(i==0){l[i]=0;}else{l[i]=__gcd(a[i-1],l[i-1]);}
  }
  for(int i=n-1;i>=0;i--){
    if(i==n-1){r[i]=0;}else{r[i]=__gcd(a[i+1],r[i+1]);}
  }
  for(int i=0;i<n;i++){
    chmax(ans,__gcd(l[i],r[i]));
  }
  cout << ans << endl;
}