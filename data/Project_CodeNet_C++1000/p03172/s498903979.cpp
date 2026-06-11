#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

ll dp[110][110000];//dp[i][j]=i番目の子供までにjこ配る通り数
ll sum[110][110000];//sum[i][j]=dp[i][0]+dp[i][1]+..+dp[i][j];

int main(){cout<<fixed<<setprecision(20);
		   ll n,k;
           cin>>n>>k;
           vll a(n+1);
           rep(i,1,n+1)cin>>a[i];
           rep(j,0,k+1)sum[0][j]=1;
           
           dp[0][0]=1;
           rep(i,1,n+1){
             rep(j,0,k+1){
              dp[i][j]+=sum[i-1][j];
              if(j-a[i]-1>=0)dp[i][j]-=sum[i-1][j-a[i]-1];
                //(dp[i-1][j]+dp[i-1][j-1]+...+dp[i-1][j-a[i]];) 
               sum[i][j]+=dp[i][j];
               if(j-1>=0)sum[i][j]+=sum[i][j-1];
               dp[i][j]%=inf;
               sum[i][j]%=inf;
              //cout<<dp[i][j]<<" ";
             }
            // cout<<endl;
           }
           if(dp[n][k]<0)dp[n][k]+=inf;
             cout<<dp[n][k]<<endl;
}