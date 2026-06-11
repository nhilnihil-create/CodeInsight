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


const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

void solve(){
     int n;cin >> n;
     vector<ll>a(n);
     for(int i = 0;i<n;i++) cin >> a[i];
     vector<ll>r(n);
     vector<ll>l(n);
     for(int i = 0;i<n;i++)
        if(i==0) l[i] = 0;
        else l[i] = gcd(a[i-1],l[i-1]);
     for(int i = n-1;i>=0;i--)
        if(i==n-1) r[i] = 0;
        else r[i] = gcd(r[i+1],a[i+1]);
     ll maxi = 0;
     for(int i = 0;i<n;i++){
        maxi = max(gcd(l[i],r[i]),maxi);
     }
     cout << maxi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}