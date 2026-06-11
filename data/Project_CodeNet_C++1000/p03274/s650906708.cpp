#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n,k; cin>>n>>k;
  vector<int>p,m;
  for(int i=0; i<n; i++){
    int a; cin>>a;
    if(a==0) k--;
    else if(a>0){
      p.push_back(a);
    }
    else{
      m.push_back(-a);
    }
  }
  int ans=1e9;
  if(k==0){
    cout << 0 << endl;
    return 0;
  }
  sort(m.begin(),m.end());
  if(p.size()>=k){
    ans = min(ans,p.at(k-1));
  }
  if(m.size()>=k){
    ans = min(ans,m.at(k-1));
  }
  for(int i=1; i<k; i++){
    if(k-i-1>=p.size()||i-1>=m.size())continue;
    int x = p.at(k-i-1);
    int y = m.at(i-1);
    ans = min(ans,x+y+min(x,y));
  }
  cout << ans << endl;
  
  
  
}