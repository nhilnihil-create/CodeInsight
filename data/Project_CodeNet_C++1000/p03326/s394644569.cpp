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
using vll=vector<ll>;
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

ll dp[1100][1100][2][2][2];
//dp[i][j][k][l][m]=iこ目　jこ選んだ時の絶対値の最大値 k,l,mは正負を表す　0 - 1 +

int main(){cout<<fixed<<setprecision(20);
		   //dpかな
           ll n,m;
           cin>>n>>m;
           vll x(n+1),y(n+1),z(n+1);
           rep(i,0,n){
             cin>>x[i+1]>>y[i+1]>>z[i+1];
           }
           rep(i,1,n+1)rep(j,0,m+1)rep(p,0,2)rep(q,0,2)rep(r,0,2){
             //選ばない
             dp[i][j][p][q][r]+=dp[i-1][j][p][q][r];
             
             //選ぶ
             if(j-1>=0){
               if(j!=i)chmax(dp[i][j][p][q][r],dp[i-1][j-1][p][q][r]+(p ? x[i]:-x[i])+(q ? y[i]:-y[i])+(r ? z[i]:-z[i]));
               
               else dp[i][j][p][q][r]=dp[i-1][j-1][p][q][r]+(p ? x[i]:-x[i])+(q ? y[i]:-y[i])+(r ? z[i]:-z[i]);
             }
           }
           ll ans=0;
           rep(i,0,2)rep(j,0,2)rep(k,0,2)chmax(ans,dp[n][m][i][j][k]);
           cout<<ans<<endl;
}

