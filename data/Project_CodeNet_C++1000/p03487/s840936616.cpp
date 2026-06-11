#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  map<int,int> m;
  rep(i,0,n){
    int a;
    cin>>a;
    m[a]++;
  }
  int ans=0;
  for(auto p:m){
    if(p.second>=p.first){
      ans+=p.second-p.first;
    }
    else{
      ans+=p.second;
    }
  }
  cout<<ans<<endl;
}