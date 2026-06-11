#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;
template <typename A, size_t N, typename T> void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}

long long moddiv(long long a, long long b) { return (a * modpow(b, mod - 2)) % mod; }

long long nCkmod(long long n, long long k) {
    long long denomi = 1;
    REP(i, n) {
        denomi *= (i + 1);
        denomi %= mod;
    }
    long long numera = 1;
    for (int i = n - k; i > 0; i--) {
        numera *= i;
        numera %= mod;
    }
    REP(i, k) {
        numera *= (i + 1);
        numera %= mod;
    }
    return moddiv(denomi, numera);
}

void print_binary(long long a) {
    for (int i = 31; i >= 0; i--) {
        cout << (a >> i & 1);
    }
    cout << endl;
}
double memo[301][301][301];
int n;
double func(int cnt3, int cnt2, int cnt1) {
    if (memo[cnt3][cnt2][cnt1] > 0) {
        return memo[cnt3][cnt2][cnt1];
    }
    double ans = 1;
    if (cnt3 > 0) {
        ans += (double(cnt3) / n) * func(cnt3 - 1, cnt2 + 1, cnt1);
    }
    if (cnt2 > 0) {
        ans += (double(cnt2) / n) * func(cnt3, cnt2 - 1, cnt1 + 1);
    }
    if (cnt1 > 0) {
        ans += (double(cnt1) / n) * func(cnt3, cnt2, cnt1 - 1);
    }
    if (cnt3 == 0 && cnt2 == 0 && cnt1 == 0) {
        return 0;
    }
    memo[cnt3][cnt2][cnt1] = (ans) / (1 - double(n - cnt3 - cnt2 - cnt1) / n);
    return memo[cnt3][cnt2][cnt1];
}
signed main() {
    cin >> n;
    Fill(memo, -1);
    map<int, int> cnt;
    REP(i, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    cout << func(cnt[3], cnt[2], cnt[1]) << endl;
}