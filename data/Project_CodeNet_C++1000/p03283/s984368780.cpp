#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;


signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  int n,m,q;
  cin>>n>>m>>q;
  int mp[n][n]={};
  int s[n][n]={};
  rep(i,m){
    int l,r;
    cin>>l>>r;
    mp[l-1][r-1]++;
  }
 
  rep(i,n){
    rep(j,n){
      // cout<<mp[i][j]<<" ";
    }
    //cout<<endl;
  }
  s[0][0]=mp[0][0];
  //cout<<mp[0][0]<<" "<<s[0][0]<<endl;
  repi(i,1,n){
    s[i][0]=s[i-1][0]+mp[i][0];
    s[0][i]=s[0][i-1]+mp[0][i];
  }
  repi(i,1,n){
    repi(j,1,n){
      s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mp[i][j];
    }
  }
  rep(i,n){
    rep(j,n){
      // cout<<s[i][j]<<" ";
    }
    //cout<<endl;
  }
  rep(i,q){
    int x,y;
    cin>>x>>y;
    x--;y--;
    if(x==0){
      cout<<s[y][y]<<endl;
    }else{
      cout<<s[y][y]-s[y][x-1]-s[x-1][y]+s[x-1][x-1]<<endl;
    }
  }
      
    

  return 0;
}
