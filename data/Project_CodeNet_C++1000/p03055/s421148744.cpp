//code by lynmisakura.wish to be accepted!
/****************************/
#include<bits/stdc++.h>
using namespace std;
/***************************/
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
 
//const long long INF = 1LL << 55;
 
#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//木の直径を測る
#define MAX_N 200020
vector<int> G[MAX_N];
int n;
int visited[MAX_N];
int longest_from_zero = 0,farest_from_zero = 0;
int diameter;
void dfs(int x,int d){
   visited[x] = 1;
   if(d > longest_from_zero){
      longest_from_zero = d;
      farest_from_zero = x;
   }
   for(auto i : G[x]){
      if(!visited[i]){
         dfs(i,d + 1);
      }
   }
}
void dfs2(int x,int d){
   visited[x] = 1;
   if(d > diameter){
      diameter = d;
   }
   for(auto i : G[x]){
      if(!visited[i]){
         dfs2(i,d + 1);
      }
   }
}
int main(void){
   cin.tie(0);
   ios::sync_with_stdio(false);
   cin >> n;
   rep(i,n-1){
      int a,b;cin >> a >> b;
      G[--a].pb(--b);
      G[b].pb(a);
   }
   //頂点0から一番遠い点を測る
   dfs(0,0);
   //farest_from_zeroから一番遠い点を測る
   fill(visited,visited + n,0);
   dfs2(farest_from_zero,0);
   //cout << diameter << endl;
   if(diameter % 3 == 1){
      cout << "Second" << endl;
   }else{
      cout << "First" << endl;
   }
   return 0;
}