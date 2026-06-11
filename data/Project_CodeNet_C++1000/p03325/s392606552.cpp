#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;


int main(){
  
  int n; cin>>n;
  int ans{};
  for(int i=0; i<n; i++){
    int a; cin>>a;
    while(a%2==0){
      ans++;
      a/=2;
    }
  }
  cout<<ans<<endl;
  
}
