#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int n;
  cin >> n;
  int a[n+2];
  ll ans=0;
  a[0]=0,a[n+1]=0;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    ans+=abs(a[i]-a[i-1]);
    if(i==n)ans+=abs(a[n+1]-a[n]);
  }
  for(int i=1;i<=n;i++){
    if(a[i-1]<=a[i] && a[i]<=a[i+1] || a[i-1]>=a[i] && a[i]>=a[i+1]){cout << ans << endl;}
    else{cout << ans-2*min(abs(a[i-1]-a[i]),abs(a[i]-a[i+1])) << endl;}
  }

}