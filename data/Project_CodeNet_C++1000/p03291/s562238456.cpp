#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<double, double> p;

#define MOD 1000000007

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll mod = pow(10, 9) + 7;

    string S;
    cin >> S;

    vector<ll> a(S.length());
    vector<ll> c(S.length());
    vector<ll> qa(S.length());
    vector<ll> qc(S.length());

    if(S[0] == 'A') a[0] = 1;
    else if(S[0] == '?') qa[0] = 1;

    if(S[S.length() - 1] ==  'C') c[S.length() - 1] = 1;
    else if(S[S.length() - 1] == '?') qc[S.length() - 1] = 1;

    for(int i = 1; i < S.length(); i++) {
        if(S[i] == 'A') a[i] = 1;
        else if(S[i] == '?') qa[i] = 1;
        a[i] += a[i - 1];
        qa[i] += qa[i - 1];
    }

    for(int i = S.length() - 2; i >= 0; i--) {
        if(S[i] == 'C') c[i] = 1;
        else if(S[i] == '?') qc[i] = 1;
        c[i] += c[i + 1];
        qc[i] += qc[i + 1];
    }

    ll ans = 0;

    for(int i = 1; i < S.length() - 1; i++) {

        if(S[i] != 'B' && S[i] != '?') continue;

        ll as = a[i - 1] * (modpow(3, qa[i - 1], mod) % mod);
        as %= mod;
        as += qa[i - 1] * (modpow(3, qa[i - 1] - 1LL, mod) % mod);
        as %= mod;

        ll cs = c[i + 1] * (modpow(3, qc[i + 1], mod) % mod);
        cs %= mod;
        cs += qc[i + 1] * (modpow(3, qc[i + 1] - 1LL, mod) % mod);
        cs %= mod;

        //cerr << c[i + 1] << endl;

        ans += (as * cs) % mod;
        ans %= mod;
    }

    cout << ans << endl;
}