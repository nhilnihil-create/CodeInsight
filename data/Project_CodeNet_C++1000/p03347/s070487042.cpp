#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n;
  cin >> n;
  vector<ll>a(n);
  for(int i=0; i<n; i++ ){
    cin >> a[i];
    if(a[i]>i || a[i]-a[i-1]>1){
     cout << -1 << endl;
     return 0;
    }
  }
  reverse(a.begin(),a.end());
  ll ans=a[0];
  for(int i=1; i<n ;i++){
    if(a[i]!=a[i-1]-1) ans+=a[i];
  }
  cout << ans << endl;
}
  
  
  
  
