//code by lynmisakura.wish to be accepted!
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>

#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

/***************************/
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<long long> vl;
typedef pair<ll, ll> pi;
typedef vector<pair<ll, ll> > vpi;

//const long long INF = 1LL << 55;

#define itn ll
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
const int MaxN=10000010,mod=998244353;
int fac[MaxN*2],ifac[MaxN*2];
long long inv(int a,int p=mod){return a==1?1:(1+p*(a-inv(p%a,a)))/a%p;}
int C(int n,int m){return m<0||m>n?0:1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;}

#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

map<pair<string,string>,long long> m;

int main(void){
    
    ll n;cin >> n;
    string s;cin >> s;
    for(int i = 0;i < (1 << n);i++){
        string p,q;p = q = "";
        for(int j = 0;j < n;j++){
            if(i >> j & 1)p += (char)s[n+j];
            else q += (char)s[n+j];
        }
        reverse(all(p));
        reverse(all(q));
        m[mp(p,q)]++;
    }
    /*for(auto i : m){
        cout << i.ff.ff << " " << i.ff.ss << " " << i.ss << endl;
    }*/
    long long ans = 0;
    for(int i = 0;i < (1 << n);i++){
        string p,q;p = q = "";
        for(int j = 0;j < n;j++){
            if(i >> j & 1)p += (char)s[j];
            else q += (char)s[j];
        }
        ans += m[mp(p,q)];
    }
    cout << ans << endl;
    return 0;
}


