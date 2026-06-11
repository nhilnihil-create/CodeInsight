#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;
const int N = 1e6 + 10;

long long modpow(long long n, long long k, long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
  int n;cin >> n;
  vector<int>x(n),y(n),h(n);
  for(int i = 0;i<n;i++){
    cin >> x[i] >> y[i] >> h[i];
  }
  for(int nx = 0;nx<=100;nx++){
    for(int ny = 0;ny<=100;ny++){
    bool ok = 1;int now = 0;int lim = 2e9;
        for(int i = 0;i<n;i++){
            int a = abs(x[i]-nx)+abs(y[i]-ny);
            int dh = h[i]+a;
            if(h[i]==0){
                lim = min(dh,lim);
                continue;
            }
            if(now == 0){
                now = dh;
            }
            else{
                if(dh!=now) ok = 0;
            }
        }
        now = max(now,1);
        if(now>lim) ok = 0;
        if(ok){
            cout << nx <<' '<< ny <<' '<< now;
            return;
        }
    }
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
