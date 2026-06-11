#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD=1e9+7;

ll rep_pow(int n, int p) {
    if (p == 0) {
        return 1;
    }
    if (p % 2 == 0) {
        ll t = rep_pow(n, p / 2);
        return t * t % MOD;
    } else {
        return n * rep_pow(n, p - 1) % MOD;
    }
}

int main() {
    string s; cin >> s;
    int n=s.size();
    vector<ll> coma(n);
    vector<ll> comc(n);
    ll a_count=0, c_count=0;
    ll aq=0, cq=0;
    for (int i=0; i<=n-3; ++i) {
        if (s[i]=='A') {
            ++a_count;
        } else if (s[i]=='?') {
            ++aq;
        }
        if (aq==0) {
            coma[i+1]=a_count;
        } else {
            coma[i+1]=(3*a_count+aq)%MOD*rep_pow(3, aq-1)%MOD;
        }
    }
    for (int i=n-1; i>=2; --i) {
        if (s[i]=='C') {
            ++c_count;
        } else if (s[i]=='?') {
            ++cq;
        }
        if (cq==0) {
            comc[i-1]=c_count;
        } else {
            comc[i-1]=(3*c_count+cq)%MOD*rep_pow(3, cq-1)%MOD;
        }
    }
    ll ans=0;
    for (int i=1; i<n-1; ++i) {
        if (s[i]=='B'||s[i]=='?') {
            ans+=coma[i]*comc[i]%MOD;
            ans%=MOD;
        }
    }
    cout << ans;
    return 0;
}