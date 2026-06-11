#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using lb=long double;
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

int main(){cout<<fixed<<setprecision(20);
		   vvin c(3,vin(3));
           rep(i,0,3)rep(j,0,3)cin>>c[i][j];
           rep(i,0,101)rep(j,0,101)rep(k,0,101){
             vin a(3);
             vin b(3);
             a[0]=i;a[1]=j;a[2]=k;
             b[0]=c[0][0]-a[0];b[1]=c[0][1]-a[0];b[2]=c[0][2]-a[0];
             bool ans=true;
             rep(p,0,3)rep(q,0,3)if(c[p][q]!=a[p]+b[q])ans=false;
             if(ans){
              cout<<"Yes"<<endl;
               return 0;
             }
           }
           cout<<"No"<<endl;
}