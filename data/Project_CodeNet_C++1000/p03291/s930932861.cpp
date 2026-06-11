#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

long long powMod(long long x, long long n, long long m) {
    long long res = 1;
    while (n > 0) {
        if ((n & 1) == 1) res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

int main() {

    string S;
    cin >> S;
    int N = S.length();
    vector<ll> blank_left(N + 1, 0), blank_right(N + 1, 0);
    vector<ll> left(N + 1, 0), right(N + 1, 0);
    rep(i,N) {
        left[i + 1] = left[i];
        blank_left[i + 1] = blank_left[i];
        if (S[i] == 'A') left[i + 1] += powMod(3, blank_left[i], MOD);
        else if (S[i] == '?') {
            blank_left[i + 1]++;
            left[i + 1] *= 3;
            left[i + 1] %= MOD;
            left[i + 1] += powMod(3, blank_left[i], MOD);
        }
        left[i + 1] %= MOD;
    }
    for (int i = N - 1; i >= 0; i--) {
        right[i] = right[i + 1];
        blank_right[i] = blank_right[i + 1];
        if (S[i] == 'C') right[i] += powMod(3, blank_right[i + 1], MOD);
        else if (S[i] == '?') {
            blank_right[i]++;
            right[i] *= 3;
            right[i] %= MOD;
            right[i] += powMod(3, blank_right[i + 1], MOD);
        }
        right[i] %= MOD;
    }

    ll ans = 0;
    rep(i,N) {
        if (S[i] != 'B' && S[i] != '?') continue;
        ans += left[i] * right[i + 1];
        ans %= MOD;
    }

    cout << ans << endl;
    
    return 0;
}