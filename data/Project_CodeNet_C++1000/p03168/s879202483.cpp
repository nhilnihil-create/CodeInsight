// g++ -std=c++14

//Difficulty according to solve count during contest:
//A B C D H F E I G K L M N P S O Q R J U Z Y X T V W

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(c) (c.begin(),c.end())
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define int ll
int mod = 1e9 + 7;
int32_t main(){
  int n;
  cin >> n;
  vector<vector<long double> > dp(n, vector<long double>(n + 1, 0.0));
  vector<long double> p(n);
  for(int i = 0; i < n; i++)
    scanf("%Lf", &p[i]);
  dp[0][0] = 1 - p[0];
  dp[0][1] = p[0];
  for(int i = 1; i < n; i++){
    for(int j = 0; j <= i + 1; j++){
      if(j != 0)
        dp[i][j] += (dp[i - 1][j - 1] * p[i]);
      dp[i][j] += (dp[i - 1][j] * (1 - p[i]));
    }
  }
  long double ans = 0;
  for(int i = n; i > n / 2; i--)
    ans += dp[n - 1][i];
  printf("%.12Lf\n", ans);
}
