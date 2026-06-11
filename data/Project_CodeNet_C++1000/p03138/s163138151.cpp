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
ll c[maxn];

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
    rep (i,1,n) {
        read (c[i]);
    }
    rep (i,0,60) {
        rep (j,1,n) {
            if((c[j]>>i)&1) {
                cnt[i]++;
            }
        }
    }
    ll ans = 0,res = 0;
    per (i, 60 , 0) {
        if((res|(1ll<<i))>k) {
            ans=ans+1ll*cnt[i]*qpow (2,i);
        }
        else {
            ans=ans+1ll*max (cnt[i],n-cnt[i])*qpow (2,i);
            if(n-cnt[i]>cnt[i]) res+=qpow (2,i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
