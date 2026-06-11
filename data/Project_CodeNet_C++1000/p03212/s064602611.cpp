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

ll dp[11][2][2][2][2];//dp[i][j][3][5][7] i桁　j：flag

int main(){cout<<fixed<<setprecision(20);
		   string s;
           cin>>s;
           int n=s.size();
           dp[0][0][0][0][0]=1;
           rep(i,1,n+1)rep(a,0,2)rep(b,0,2)rep(c,0,2){
             int h=s[i-1]-'0';
             rep(l,0,10){
              if(l!=3&&l!=5&&l!=7&&l!=0)continue;
               if(l==3){
                 if(a-1>=0){
                   dp[i][1][a][b][c]+=dp[i-1][1][0][b][c]+dp[i-1][1][1][b][c];
                   if(l<h)dp[i][1][a][b][c]+=dp[i-1][0][0][b][c]+dp[i-1][0][1][b][c];
                   if(l==h)dp[i][0][a][b][c]+=dp[i-1][0][0][b][c]+dp[i-1][0][1][b][c];
                           }
               }
               if(l==5){
                 if(b-1>=0){
                   dp[i][1][a][b][c]+=dp[i-1][1][a][b][c]+dp[i-1][1][a][b-1][c];
                   if(l<h)dp[i][1][a][b][c]+=dp[i-1][0][a][b][c]+dp[i-1][0][a][b-1][c];
                   if(l==h)dp[i][0][a][b][c]+=dp[i-1][0][a][b][c]+dp[i-1][0][a][b-1][c];
                           }
               }
               if(l==7){
                 if(c-1>=0){
                   dp[i][1][a][b][c]+=dp[i-1][1][a][b][c]+dp[i-1][1][a][b][c-1];
                   if(l<h)dp[i][1][a][b][c]+=dp[i-1][0][a][b][c]+dp[i-1][0][a][b][c-1];
                   if(l==h)dp[i][0][a][b][c]+=dp[i-1][0][a][b][c]+dp[i-1][0][a][b][c-1];
                           }
               }
              if(l==0){
                 if(a==0&&b==0&&c==0)
                dp[i][1][a][b][c]+=1;
               }
               //cout<<i<<" "<<l<<"  "<<a<<" "<<b<<" "<<c<<"  "<<dp[i][0][a][b][c]<<" "<<dp[i][1][a][b][c]<<endl;
             }
           }
           int ans=0;
           ans=dp[n][0][1][1][1]+dp[n][1][1][1][1];
           cout<<ans<<endl;
}