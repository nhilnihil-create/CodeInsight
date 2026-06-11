#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  int n; cin>>n;
  vector<int> v(n);
  rep(i,n)cin>>v.at(i);
  int c,ans=0;
  rep(i,n){
    cin>>c;
    v.at(i)-=c;
    if(v.at(i)>0)ans+=v.at(i);
  }
  cout<<ans;
}