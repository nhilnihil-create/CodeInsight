#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gpu_hash_map<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
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
const int mxN = 100001;
ll arr[mxN];
ll b[mxN];
ll srt[mxN];
int n;
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    ll sum = 0;
    owo(i, 0, n) {
        cin>>arr[i];
        sum+=arr[i];
    }
    owo(i, 0, n) {
        cin>>b[i];
        srt[i] = arr[i]-b[i];
        sum-=b[i];
    }
    if(sum<0) {
        cout<<"-1\n";
    }else {
        ll diff = 0;
        int ans = 0;
        owo(i, 0, n) {
            if(arr[i]<b[i]) {
                ans++;
                diff+=b[i]-arr[i];
            }
        }
        sort(srt, srt+n);
        reverse(srt, srt+n);
        owo(i, 0, n) {
            if(diff<=0)break;
            diff-=srt[i];
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}