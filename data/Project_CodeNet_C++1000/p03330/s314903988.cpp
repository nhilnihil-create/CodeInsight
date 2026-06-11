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
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

ll cost[4][33];

int main(){cout<<fixed<<setprecision(10);
		   //前処理O(n^2*c)
           //色の選び方O(c*3)
           int n,C;
           cin>>n>>C;
           vector<vin> d(C+1,vin(C+1));
           rep(i,1,C+1)rep(j,1,C+1)cin>>d[i][j];
           vector<vin> c(n,vin(n));
           rep(i,0,n)rep(j,0,n)cin>>c[i][j];
           int pp=0;
            rep(i,1,C+1){
            rep(j,0,n){
             rep(k,0,n){
               pp=d[c[j][k]][i];
               if((j+k)%3==0){
                 cost[0][i]+=pp;
               }
               else if((j+k)%3==1){
                 cost[1][i]+=pp;
               }
               else{
                 cost[2][i]+=pp;
               }
             }
            }
           }
           
           ll ans=inf;
           rep(i,1,C+1){
            rep(j,1,C+1){
             rep(k,1,C+1) {
               if(i==j||j==k||i==k)continue;
              ll cnt=cost[0][i]+cost[1][j]+cost[2][k];
               chmin(ans,cnt);
             }
            }
           }
           cout<<ans<<endl;
}