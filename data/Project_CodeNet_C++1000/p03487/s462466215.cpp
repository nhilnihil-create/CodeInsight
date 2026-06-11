#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;


int main(){
  
  map<int,int> m;
  int n; cin>>n;
  while(n--){
    int a; cin>>a;
    m[a]++;
  }  
  int ans{};
  for(auto i:m){
    if(i.first<i.second)ans += i.second-i.first;
    if(i.first>i.second)ans += i.second;
  }
  cout<<ans<<endl;
}
