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
int main(){cout<<fixed<<setprecision(20);
		  //Sr-Slがmの倍数　→ Sr=Sl(mod m)
          // Si = k (0<=k<=m-1)となる iの個数を記録して
           // Σi C 2 =Σi(i-1)/2
           ll n,m;
           cin>>n>>m;
           vll a(n);
           vll sum(n,0);
           
           map<ll ,ll> cnt;
           cnt[0]++;
           
           rep(i,0,n){
            cin>>a[i];
             
            sum[i]+=a[i];
            if(i-1>=0)sum[i]+=sum[i-1];
             
            sum[i]%=m;
            
             cnt[sum[i]]++;
           }
           
           ll ans=0;
           for(auto v:cnt){
             ans+=v.second*(v.second-1)/2;
           }
           cout<<ans<<endl;
}