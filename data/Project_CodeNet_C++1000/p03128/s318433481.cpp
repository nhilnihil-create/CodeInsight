#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define FOR(e, c) for (auto &e : c)
#define SORT(v, n) sort(v, v + n);
#define vsort(v) sort(v.begin(), v.end());
#define rvisort(v) sort(v.begin(), v.end(), greater<int>());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
// #define int long long
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using ul = unsigned long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}


const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
        // 1 2 3 4 5 6 7 8 9
int f[] = {2,5,5,4,5,6,3,7,6};

int dp[10005]; // dp[i]:=マッチをi個使うときの桁数の最大

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  int n,m;
  cin>>n>>m;
  vi a(m);
  rep(i,m) cin>>a[i];
  vsort(a);
  
  rep(i,m) {
    dp[f[a[i]-1]]=1;
  }
  rep(i,n+1){
    rep(j,m) {
      if(dp[max(0,i-f[a[j]-1])]==0) continue;
      chmax(dp[i],dp[max(0,i-f[a[j]-1])]+1);
    }
  }
  
  string ans="";
  int remain=dp[n];
  int match=n;
  while(match>0){
    for(int i=m-1; i>=0; i--){
      if(remain==1){
        if(f[a[i]-1]==match){
          ans+='0'+a[i];
          match-=f[a[i]-1];
          remain--;
          break;
        }
      }
      else if(dp[match-f[a[i]-1]]==remain-1){
        ans+='0'+a[i];
        match-=f[a[i]-1];
        remain--;
        break;
      }
    }
  }
  cout<<ans<<endl;
}
