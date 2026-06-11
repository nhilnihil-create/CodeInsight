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
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using ul = unsigned long;
 
const int MOD = 1e9+7;
const int INF = 1e9;
const ll LINF = 1e18;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }

signed main()
{
  int h,w,n,y,x; cin>>h>>w>>n>>y>>x;
  string s,t; cin>>s>>t;
  
  x--;y--;
  
  // left, right
  int left=0, right=w;
  
  // 最終ターンの先手の手から、後手が勝つためにいないといけないエリアを決める
  // 最終ターンの後手の手は評価する必要はない
  if(s[n-1]=='L')left++;
  else if(s[n-1]=='R')right--;
  string ans="YES";
  for(int i=n-2;i>=0;i--){
    // このターンの後手の手から、手を打つ前に居ていいエリアを広げられるか判断
    if(t[i]=='L') right=min(right+1,w);
    else if(t[i]=='R') left=max(left-1,0);
    // 先手の手からエリアを狭め、前ターンに居なければならないエリアを決める
    if(s[i]=='L') left++;
    else if(s[i]=='R') right--;
    // 居ていいエリアがつぶれる
    if(left>=right) ans="NO";
  }
  if(x<left||right<=x) ans="NO";
  
  // up, down
  left=0; right=h;
  if(s[n-1]=='U')left++;
  else if(s[n-1]=='D')right--;
  for(int i=n-2;i>=0;i--){
    if(t[i]=='U') right=min(right+1,h);
    else if(t[i]=='D') left=max(left-1,0);
    if(s[i]=='U') left++;
    else if(s[i]=='D') right--;
    if(left>=right) ans="NO";
  }
  if(y<left||right<=y) ans="NO";
  
  cout<<ans<<endl;
}
