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

ll dp[200100];


int main(){cout<<fixed<<setprecision(10);
		   //dp[n] ...i番目までの通り数
           //初めての色ならスルー　2回目以降ならdp[i]=dp[i-1]+dp[x] xは直前の同色の位置
           //(x!=i-1)
           int n;
           cin>>n;
           vin c(n+1);
           rep(i,1,n+1)cin>>c[i];
           map<int,int> last;//最後にいつ出てきたか
           dp[0]=1;
           rep(i,1,n+1){
             dp[i]=dp[i-1];
             int g=last[c[i]];
             if(g>0&&g!=i-1)dp[i]+=dp[g];
             last[c[i]]=i;
             dp[i]%=inf;
           }
                     /* rep(i,0,n+1){
                       cout<<i<<" "<<dp[i]<<endl; 
                      }*/
           cout<<dp[n]<<endl;
}