#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (ll i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using ld=long double;
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

int lgcd[110000];
int rgcd[110000];

int main(){cout<<fixed<<setprecision(20);
		   int n;
           cin>>n;
           vin a(n+1);
           rep(i,1,n+1)cin>>a[i];
           
           rep(i,1,n+1){
            lgcd[i]=__gcd(a[i],lgcd[i-1]);
           }
           for(int i=n;i>=1;i--){
            rgcd[i]=__gcd(a[i],rgcd[i+1]); 
           }
           int ans=0;
           rep(i,1,n+1){
             chmax(ans,__gcd(lgcd[i-1],rgcd[i+1]));
           }
           cout<<ans<<endl;
}