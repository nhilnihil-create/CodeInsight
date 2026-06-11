//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
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
typedef vector<ll> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pi;
typedef vector<pair<ll, ll>> vpi;
 
//const long long INF = 1LL << 55;
 
#define itn ll
#define endl '\n'
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(ll i = 0;i < n;i++)
#define rep(i,n) for(ll i = 0;i < n;i++)
#define flush fflush(stdout)
#define rrep(i,n) for(ll i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define ioboost cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20)
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, ll mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

int main(void){
   ioboost;
   
   int n;cin >> n;
   set<int> ans;
   if(n == 3){
      vi a = {2, 5, 63};
      for(auto i : a)cout <<i << endl;
   }else if(n == 4){
      vi a = {2, 5, 20, 63};
      for(auto i : a)cout <<i << endl;
   }else if(n == 5){
      vi a = {2, 5, 20, 30, 63};
      for(auto i : a)cout <<i << endl;
   }else{
      vl a;
      ll sum = 0;
      int ad[4] = {2,3,4,6};
      rep(i,n){
         ans.insert(6 * (i/4) + ad[i%4]);
         sum += 6 * (i/4) + ad[i%4];
      }
      switch(sum % 6){
         case 2:
            ans.erase(8);
            ans.insert(6*(n/4 + 1));
            break;
         case 3:
            ans.erase(9);
            ans.insert(6*(n/4 + 1));
            break;
         case 5:
            ans.erase(9);
            ans.insert(6*((n-1)/4 + 1) + 4);
            break;
         default:break;
      }
      
      for(auto i : ans){
         if(i > 30000){
            cout << i - 6 << endl;
         }else{
            cout << i << endl;
         }
      
      }
   }
}