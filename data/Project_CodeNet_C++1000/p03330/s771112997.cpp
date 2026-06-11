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

ll cost[33][3];

int main(){cout<<fixed<<setprecision(20);
		   int n,c;
           cin>>n>>c;
           vvin d(c,vin (c));
           rep(i,0,c)rep(j,0,c)cin>>d[i][j];
           vvin k(n,vin (n));
           rep(i,0,n)rep(j,0,n){
             cin>>k[i][j];
             k[i][j]--;
           }
           rep(p,0,c){
             rep(i,0,n)rep(j,0,n){
               if((i+j)%3==0){
                 cost[p][0]+=d[k[i][j]][p];
               }
               else if((i+j)%3==1){
                 cost[p][1]+=d[k[i][j]][p];
               }
               else{
                 cost[p][2]+=d[k[i][j]][p];
               }
             }
           }
           ll ans=INF;
           rep(p,0,c){//0
            rep(q,0,c){
              rep(r,0,c){
                if(p==q||q==r||r==p)continue;
                chmin(ans,cost[p][0]+cost[q][1]+cost[r][2]);
              }
            }
           }
           cout<<ans<<endl;
}