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
const long double pi=acos(-1);

int main(){cout<<fixed<<setprecision(10);
		   int n;
           cin>>n;
           vin d(n);
           rep(i,0,n)cin>>d[i];
           map<int,int> cnt;
           rep(i,0,n)cnt[d[i]]++;
           bool zero=false;
           vin time(25,0);
           time[0]++;
           time[24]++;
           vin mi;
           int micnt=0;
           for(auto v:cnt){
                if(v.first==0)zero=true;
                else if(v.first==12){
                  if(v.second>=2)zero=true;
                  time[12]++;
                }
               else if(v.second>=3)zero=true;
               else if(v.second==2){
                time[v.first]++;
                time[24-v.first]++;
               }
               else{
                 micnt++;
                 mi.pb(v.first);
               }
           }
           if(zero){
            cout<<0<<endl;
             return 0;
           }
           int ans=0;
           //cout<<mi[0]<<mi[1]<<endl;
           for (int bit = 0; bit < (1 <<micnt ); ++bit) {
               vin ktime(25);
               ktime=time;
               for (int i = 0; i < micnt; ++i) {
                if (bit & (1 << i)){
                  ktime[mi[i]]++;
                }
                 else{
                   ktime[24-mi[i]]++;
                 }
               }
             int g=inf;
             int hu=0;
             rep(i,1,25){
               if(ktime[i]){
                chmin(g,i-hu);
                hu=i; 
               }
             }
             chmax(ans,g);
           }
           
           
           cout<<ans<<endl;
}

