#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  string s,t; cin>>s>>t;
  vector<int> a(26),b(26);
  for(auto i:s){
    a.at(i-'a')++;
  }
  for(auto i:t){
    b.at(i-'a')++;
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  cout<<(a==b?"Yes":"No")<<endl;
  
}

