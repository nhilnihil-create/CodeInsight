//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
 
const long long MOD = 998244353;
const long long mod = 1000000007;
const long long INF = 10000000000000;
 
#define itn int
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int p[13];
int main(void){
   int n;cin >> n;
   vector<int> d(n);rep(i,n) cin >> d[i];
   
   p[0]++;
   rep(i,n){
      p[d[i]]++; 
      if(d[i] == 0 || p[d[i]] == 3){
         cout << 0 << endl;
         return 0;
      }
   }
   int ans = -1;
   for(int s = 0;s < (1 << 12);s++){
      vector<int> d2(24,0);
      d2[0]++;
      for(int i = 1;i <= 11;i++){
         if(p[i] == 0) continue;
         else if(p[i] == 1){
            if((s >> i) & 1){
               d2[i] = 1;
            }else{
               d2[24 - i] = 1;
            }
         }else{
            d2[i] = d2[24 - i] = 1;
         }
      }
      if(p[12] == 1){
         d2[12] = 1;
      }else if(p[12] == 12){
         cout << 0 << endl;
         return 0;
      }
      
      //時差の最小値を求める
      vector<int> t; //点が存在する時刻を格納する
      for(int i = 0;i < 24;i++){
         if(d2[i]) t.pb(i);
      }
      t.pb(24);
      
      int dmin = 100;
      for(int i = 0;i < t.size() - 1;i++){
         mins(dmin,t[i+1] - t[i]);
      }
      maxs(ans,dmin);
   }
   cout << ans << endl;
   return 0;
   
}