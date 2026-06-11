// #pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define String std::string
#define fir first
#define sec second
#define mp std::make_pair
#define Pair std::pair<int, int>
#define Map std::map< int, int >
#define Vector std::vector<int>

typedef long long ll;
typedef unsigned long long ull;

const int N = 100000 + 5;
const int M = 3000 + 5;
const int MOD = 1e9 + 7;
const int inv2 = 500000004;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

template<class T>
inline T readT() {
    T res = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) res = (res << 1) + (res << 3) + ch - '0';
    return res * f;
}
#define read readT<int>

int n, k;
int buc[N * 2];

int main() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        buc[i % k]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = (k - i % k) % k;
        if ((tmp + tmp) % k == 0) ans += (ll)buc[tmp] * buc[tmp];
    }
    printf("%lld\n", ans);
    return 0;
}