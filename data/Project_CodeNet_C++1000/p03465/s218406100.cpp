#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e3+10;
bitset <N*N> dp;
ll a[N];
int32_t main(){
    ll n;
    cin >> n;
    ll z=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        z+=a[i];
    }
    z=(z+1)/2;
    dp[0]=1;
    for (int i=1;i<=n;i++){
        dp=(dp | (dp << a[i]));
    }
    for (int i=z;i<N*N;i++) if (dp[i]) kill(i);
}
