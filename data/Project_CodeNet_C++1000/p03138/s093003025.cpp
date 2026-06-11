#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const int MOD=1000000007;
int INF=100100100100100;
const int d=50;
int a[100];
int bi[100];
int dp[100][2];
signed main(){
  int n,k;cin>>n>>k;
  rep(i,n){
    int x;cin>>x;
    rep(j,d){
      if(x & (1LL<<(d-j-1)))a[j]++;
    }
    
  }
  rep(j,d){
    if(k & (1LL<<(d-j-1)))bi[j]=1;
    //cout<<a[j]<<" "<<bi[j]<<endl;
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0]=0;
  rep(i,d){
    int c0=(1LL<<(d-i-1))*a[i],c1=(1LL<<(d-i-1))*(n-a[i]);
    if(dp[i][1]>=0){
      chmax(dp[i+1][1],dp[i][1]+max(c0,c1));
    }
    if(dp[i][0]>=0){
      if(bi[i]==0)chmax(dp[i+1][0],dp[i][0]+c0);
      else{
        chmax(dp[i+1][1],dp[i][0]+c0);
        chmax(dp[i+1][0],dp[i][0]+c1);
      }
    }
  }
  cout<<max(dp[d][0],dp[d][1])<<endl;
  return 0;
}
