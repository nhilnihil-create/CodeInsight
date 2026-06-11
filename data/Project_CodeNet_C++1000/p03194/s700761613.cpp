#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,p;
  cin >> n >> p;
  vector<ll> x(1000000);
  if(n==1){
    cout << p << endl;
  }
  else{
  for(int i=2;i<=1000000;i++){
    while(p%i==0){
      x[i]++;
      p/=i;
    }
  }
  ll ans=1;
  for(int i=2;i<=1000000;i++){
    for(int j=1;j<=x[i]/n;j++){
      ans*=i;
    }
  }
  cout << ans << endl;
  }
}