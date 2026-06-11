#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vector<ll> > vvl;
typedef vector<vector<P> > vvp;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n,A,B,C;
int l[10];
int ans=1e9;

void dfs(int cost,int num ,int a, int b, int c){
  if(num==n){
    if(a==0||b==0||c==0)return ;
    cost+=abs(a-A)+abs(b-B)+abs(c-C)-30;
    chmin(ans,cost);
    return;
  }
  dfs(cost+10,num+1,a+l[num],b,c);
  dfs(cost+10,num+1,a,b+l[num],c);
  dfs(cost+10,num+1,a,b,c+l[num]);
  dfs(cost,num+1,a,b,c);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  cin >> n >> A >> B >> C;
  rep(i,n) cin >> l[i];
  
  dfs(0,0,0,0,0);
  cout << ans << endl;
  return 0;     
}
