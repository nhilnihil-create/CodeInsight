//#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
gpu_hash_table<int, int> mp;
#define ordered_set tree<ttgl, null_type,less<ttgl>, rb_tree_tag,tree_order_statistics_node_update>
 */
using ll = long long;
using ld = long double;
const ll MOD = 924844033;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 1000001;
string s;
int q;
int n;
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>s>>q;
    int k;
    while(q--) {
      cin>>k;
      ll res = 0;
      ll d, m, dm;
      d = m = dm = 0;
      owo(i, 0, n) {
        if(i>=k) {
          if(s[i-k]=='D') {
            dm-=m;
            d--;
          }
          if(s[i-k]=='M') {
            m--;
          }
        }
        if(s[i]=='D') {
          d++;
        }
        if(s[i]=='M') {
          m++;
          dm+=d;
        }
        if(s[i]=='C') {
          res+=dm;
        }
        //cout<<d<<" "<<m<<" "<<dm<<" "<<k<<"\n";
      }
      cout<<res<<"\n";
    }
    return 0;
}