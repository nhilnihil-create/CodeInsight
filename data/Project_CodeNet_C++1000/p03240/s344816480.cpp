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
		   int n;
           cin>>n;
           vector<pair<int,P>> r(n);
           rep(i,0,n){
             int x,y,h;
             cin>>x>>y>>h;
             r[i]=mp(h,mp(x,y));
           }
           sort(all(r));
           reverse(all(r));
           
           //全探索
           
           rep(i,0,101){
             rep(j,0,101){
               int g=-1;
               bool ok=true;
               rep(k,0,n){
                 
                 if(g==-1)g=r[k].first+abs(i-r[k].second.first)+abs(j-r[k].second.second);
                 else{
                   if(r[k].first==0){
                     if(g-abs(i-r[k].second.first)-abs(j-r[k].second.second)>0)ok=false;
                   }
                   else if(g-abs(i-r[k].second.first)-abs(j-r[k].second.second)!=r[k].first)ok=false;
                 }
               }
               if(ok){
                cout<<i<<" "<<j<<" "<<g<<endl;
                 return 0;
               }
             }
           }
}