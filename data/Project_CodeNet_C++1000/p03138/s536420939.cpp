#pragma GCC optimize(3 , "Ofast" , "inline")

#include <bits/stdc++.h>

#define rep(i , a , b) for(register int i=(a);i<=(b);i++)
#define per(i , a , b) for(register int i=(a);i>=(b);i--)


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> pi;

template<class T>
inline void read (T &x) {
    x = 0;
    int sign = 1;
    char c = getchar ();
    while (c < '0' || c > '9') {
        if ( c == '-' ) sign = - 1;
        c = getchar ();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar ();
    }
    x = x * sign;
}

const int maxn = 2e5 + 10;
const int inf = int (1e9);
const ll INF = ll (1e18);
const double PI = acos (- 1);
const int mod = 998244353;
const double eps = 1e-8;

int n;
ll k;
ll cnt[65];


ll qpow(ll a,ll b) {
    ll ans = 1;
    while (b) {
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main () {
    read (n);
    read (k);
    ll ma = 1;
    rep (i , 1 , n) {
        ll x;
        read (x);
        ll j = 0;
        while (x) {
            cnt[j]+=(x&1);
            x/=2;
            j++;
        }
        ma = max (ma , j);
    }
    ll kk = k;
    ll j = 0;
    while (kk) {
        kk /= 2;
        j ++;
    }
    ma = max (ma , j);
    bool f = 0;
    per (i , ma - 1 , 0) {
        if ( f ) {
            if ( cnt[ i ] < n - cnt[ i ] ) {
                cnt[ i ] = n - cnt[ i ];
            }
            continue;
        }
        if ( cnt[ i ] < n - cnt[ i ] ) {
            if (( k >> i ) & 1 ) {
                cnt[ i ] = n - cnt[ i ];
            }
        } else {
            if (( k >> i ) & 1 ) {
                f = 1;
            }
        }
    }
    ll ans = 0;
    rep (i,0,ma-1) {
        ans=ans+1ll*cnt[i]*qpow(2,i);
    }
    cout<<ans<<endl;
    return 0;
}
