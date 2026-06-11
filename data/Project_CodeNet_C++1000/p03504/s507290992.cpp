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
vector<vll> table;
vector<vll> sum;

int main(){cout<<fixed<<setprecision(20);
           //二次元imos
           int n,k;
           cin>>n>>k;
           int e=1e5;
           table.resize(e+1,vll(k+1));
           sum.resize(e+1,vll(k+1));
           rep(i,0,e+1){
            rep(j,0,k+1){
              table[i][j]=0;
            }
           }
           rep(i,0,n){
             int s,t,c;
             cin>>s>>t>>c;
             table[s][c]++;
             table[t][c]--;
           }
           
           rep(i,0,e+1){
            rep(j,0,k+1){
              sum[i][j]=0;
            }
           }
           rep(i,1,e+1){
            rep(j,1,k+1){
              if(sum[i-1][j]==0&&table[i][j]==1) {
                sum[i-1][j]++;              
                sum[i][j]--;
              }
              sum[i][j]+=sum[i-1][j]+table[i][j];
            /*  if(sum[i][j]==0&&table[i][j]==-1){
                sum[i][j]++;
                sum[i+1][j]--;
              }*/
            //cout<<table[i][j]<<" ";
            }
             //cout<<endl;
           }
           rep(i,1,e+1){
             rep(j,1,k+1){
              sum[i][j]+=sum[i][j-1];
             }
           }
           ll ans=0;
           rep(i,0,e+1){
            chmax(ans,sum[i][k]); 
             //cout<<ans<<" ";
           }
           cout<<ans<<endl;
          }