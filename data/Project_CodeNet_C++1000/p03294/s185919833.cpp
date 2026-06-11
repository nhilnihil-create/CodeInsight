#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n; cin>>n;
  ll ans{};
  while(n--){
    int a; cin>>a;
    ans += --a;
  }
  cout<<ans<<endl;
  
}
