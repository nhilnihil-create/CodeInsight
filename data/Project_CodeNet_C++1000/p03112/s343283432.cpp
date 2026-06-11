#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long ,long long>pll;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

 long long modpow(long long n, long long k,long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
    ll a,b,q;
    cin >> a >> b >> q;
    vector<ll>d1(a);
    vector<ll>d2(b);
    set<ll>s1;set<ll>s2;
    for(int i = 0;i<a;i++)
    {
        cin >> d1[i];
        s1.insert(d1[i]);
    }
    for(int i = 0;i<b;i++)
    {
        cin >> d2[i];
        s2.insert(d2[i]);
    }
    while(q--){
        ll x;cin >> x;
        vector<ll>p;vector<ll>j;
        auto it = s1.lower_bound(x);
        if(it!=s1.end())p.push_back(*it);
        if(it!=s1.begin()) p.push_back(*prev(it));
        it = s2.lower_bound(x);
        if(it!=s2.end())j.push_back(*it);
        if(it!=s2.begin()) j.push_back(*prev(it));
        ll ans = LLONG_MAX;
        for(int i = 0;i<p.size();i++){
            for(int k = 0;k<j.size();k++){
                ans = min(ans,abs(x-p[i])+abs(p[i]-j[k]));
                ans = min(ans,abs(x-j[k])+abs(j[k]-p[i]));
            }
        }
        cout << ans <<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}