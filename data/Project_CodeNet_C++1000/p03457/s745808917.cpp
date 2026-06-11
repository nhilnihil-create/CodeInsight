#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main(){
  int n; cin>>n;
  string ans="Yes";
  vector<vector<int>> v(n,vector<int>(3));
  rep(i,n){
    cin>>v[i][0]>>v[i][1]>>v[i][2];
  }
  int t,x,y;
  rep(i,n){
    if(i==0){
      t=v[0][0];x=v[0][1];y=v[0][2];
    }
    else{
      t=v[i][0]-v[i-1][0];
      x=max(v[i][1]-v[i-1][1],-v[i][1]+v[i-1][1]);
      y=max(v[i][2]-v[i-1][2],-v[i][2]+v[i-1][2]);
    }
    if((-t+x+y)%2!=0||t<x+y){ans="No";break;}
  }
  cout<<ans;
}