#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  string s; cin>>s;
  int ans{};
  for(auto i:s){
    if(i=='+') ans++;
    else ans--;
  }
  cout << ans << endl;
  
}
