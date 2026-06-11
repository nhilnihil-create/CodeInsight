#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int main(){cout<<fixed<<setprecision(10);
		   int h,w;
           cin>>h>>w;
           vector<vin> a(h,vin(w));
           rep(i,0,h){
            rep(j,0,w){
              cin>>a[i][j];
            }
           }
           int cnt=0;
           vector<P> ans1(250010),ans2(250010);
           rep(i,0,h){
            rep(j,0,w){
              if(a[i][j]%2==1){
               ans1[cnt]=mp(i+1,j+1);
                
                if(j==w-1){
                      if(i!=h-1){
                        a[i+1][j]++;
                        ans2[cnt]=mp(i+2,j+1);
                      }
                      else{
                       continue; 
                      }
                }
                
                else{
                     a[i][j+1]++;
                  ans2[cnt]=mp(i+1,j+2);
                }
                cnt++;
              }
            }
           }
           cout<<cnt<<endl;
           rep(i,0,cnt){
            cout<<ans1[i].first<<" "<<ans1[i].second<<" "<<ans2[i].first<<" "<<ans2[i].second<<endl;
           }
}