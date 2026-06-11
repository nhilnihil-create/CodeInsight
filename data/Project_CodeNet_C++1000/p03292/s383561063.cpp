#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  vector a(3,0);
  for(auto &i:a)cin>>i;
  sort(a.begin(),a.end());
  cout<<a.at(2)-a.at(0)<<endl;
  
  
}
