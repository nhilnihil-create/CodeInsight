#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  ll x,y; cin>>x>>y;
  int ans{};
  while(x<=y){
    x*=2;
    ans++;
  }
  cout<<ans<<endl;
}
