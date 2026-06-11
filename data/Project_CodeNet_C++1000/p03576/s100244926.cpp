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
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(){cout<<fixed<<setprecision(10);
		   //端を決めるO(n^4)
           //何個含まれているか数えるO(n)
           //O(n^5)
           int n,K;
           cin>>n>>K;
           vector<P> x(n);
		   rep(i,0,n)cin>>x[i].first>>x[i].second;
           ll ans=INF;
           //cout<<ans<<endl;
           rep(i,0,n){
            rep(j,0,n){
              rep(k,0,n){
               rep(l,0,n){
                 if(i==j||k==l)continue;
                 ll xmin=min(x[i].first,x[j].first);
                 ll xmax=max(x[i].first,x[j].first);
                 ll ymin=min(x[k].second,x[l].second);
                 ll ymax=max(x[k].second,x[l].second);
                 ll num=0;
                 rep(p,0,n){
                   if(x[p].first<=xmax&&x[p].first>=xmin){
                     if(x[p].second<=ymax&&x[p].second>=ymin){
                       num++;
                     }
                   }
                 }
                 ll cnt=(xmax-xmin)*(ymax-ymin);
                 if(num>=K){
                   chmin(ans,cnt);
                 }
                 //cout<<k<<endl;
                 //if(ans==2)cout<<num<<endl;
               }
              }
            }
           }
           cout<<ans<<endl;
}