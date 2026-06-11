#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> fu;
  vector<int> sei;
  sei.push_back(0);
  rep(i,0,n){
    int x;
    cin>>x;
    if(x<0) fu.push_back(-x);
    else sei.push_back(x);
  }
  fu.push_back(0);
  reverse(fu.begin(),fu.end());
  
  int ans=1e9;
  rep(i,0,fu.size()){
    if(i+sei.size()-1<k) continue;
    if(i>k) break;
    ans=min(ans,2*fu[i]+sei[k-i]);
  }
  rep(i,0,sei.size()){
    if(i+fu.size()-1<k) continue;
    if(i>k) break;
    ans=min(ans,2*sei[i]+fu[k-i]);
  }
  cout<<ans<<endl;
}