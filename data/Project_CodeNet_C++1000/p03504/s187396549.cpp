#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,c;
  cin>>n>>c;
  bool p[c][100000];
  rep(i,0,c){
    rep(j,0,100000){
      p[i][j]=false;
    }
  }
  rep(i,0,n){
    int s,t,c;
    cin>>s>>t>>c;
    rep(j,s-1,t){
      p[c-1][j]=true;
    }
  }
  int ans=0;
  rep(i,0,100000){
    int cnt=0;
    rep(j,0,c){
      if(p[j][i]) cnt++;
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
}