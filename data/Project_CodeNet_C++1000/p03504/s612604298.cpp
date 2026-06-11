#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define INF 100000

int main()
{
  int n,cs;cin>>n>>cs;
  vector<int> s(n);
  vector<int> t(n);
  vector<int> c(n);
  int i,j;
  rep(i,n)cin>>s[i]>>t[i]>>c[i];
  vector<vector<bool>> tt(cs,vector<bool>(100010,false));
  int ans=0;
  rep(i,n)for(j=s[i]-1;j<=t[i]-1;j++)tt[c[i]-1][j]=true;
  rep(i,100010)
  {
    int count=0;
    rep(j,cs)if(tt[j][i])count++;
    ans=max(ans,count);
  }
  cout<<ans<<endl;
}
