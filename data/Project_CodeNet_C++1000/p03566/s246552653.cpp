#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

struct vectim{double v,t;};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  int te=0;
  vector<int>t(n),v(n);
  rep(i,n){cin>>t[i];t[i]*=2;}
  rep(i,n){cin>>v[i];v[i]*=2;}
  rep(i,n)te+=t[i];
  vector<int>vmax(te+1);
  int tt=1;
  rep(i,n)
  {
    repi(j,tt,tt+t[i])vmax[j]=v[i];
    tt+=t[i];
  }
  //for(auto a:vmax)cout<<a<<endl;
  vector<vector<double>>dp(40009,vector<double>(400,-1e9));
  dp[0][0]=0;
  rep(i,te)
  {
    repi(j,0,vmax[i+1]+1)
    {
      double tres=-1e9;
      if(j>0)chmax(tres,dp[i][j-1]+j-0.5);
      chmax(tres,dp[i][j]+j);
      if(j+1<=vmax[i+1])chmax(tres,dp[i][j+1]+j+0.5);


      dp[i+1][j]=tres;
      //cout<<i+1<<" "<<j<<" "<<tres<<endl;
    }
  }
  cout<<setprecision(15)<<dp[te][0]/4<<endl;


  return 0;

}
