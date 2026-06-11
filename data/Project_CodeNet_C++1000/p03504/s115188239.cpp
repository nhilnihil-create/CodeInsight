#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,c;
  cin>>n>>c;
  vector<vector<int>> d(c,vector<int>(200005));
  rep(i,n){
    int s,t,c;
    cin>>s>>t>>c;
    c--;
    d[c][s*2-1]=1;
    d[c][t*2]=-1;
  }
  rep(i,c)rep(j,200004) d[i][j+1]+=d[i][j];
  
  int ans=0;
  rep(i,200005){
    int res=0;
    rep(j,c){
      if(d[j][i]!=0) res++;
    }
    ans=max(ans,res);
  }
  cout<<ans<<endl;
}