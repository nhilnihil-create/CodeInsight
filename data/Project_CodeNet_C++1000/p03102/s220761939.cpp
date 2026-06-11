#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n,m,c;
  cin >> n >> m>> c;
  vector<int> b(m);
  rep(i,m){
    cin>>b[i];
   }
  int ans=0;
  rep(i,n){
    int sum=c;
    rep(j,m){
      int x;
      cin>>x;
      sum+=x*b[j];
    }
    if(sum>0){
      ans++;
    }
  }
  cout<<ans;
}