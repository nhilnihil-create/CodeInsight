// Zhupengfei 2018
// This program / source file is in public domain.

// Solution for problem: arc101B

#include <bits/stdc++.h>

// Common definitions
#define rep(i, a, b) for (long long i = (a); i <= (b); i++)
#define repd(i, a, b) for (long long i = (b); i >= (a); i--)
#if __cplusplus >= 201103L
#define foreach(it, container) for (it : (container))
#else
#define foreach(it, container)                                                                     \
    for (typeof((container).begin()) it = (container).begin(); it != (container).end(); ++it)
#endif
#define forever for (;;)

// Debug use
#ifdef LOCAL
#define dbg_out(x) cout << (x) << endl
#else
#define dbg_out(x)
#endif

// IO stream extensions
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, " "));
    }
    return out;
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pa) {
    out << pa.first << " " << pa.second;
    return out;
}
template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    v.clear();
    size_t siz;
    is >> siz;
    v.reserve(siz);
    T value;
    for (size_t i = 0; i < siz; i++) {
        is >> value;
        v.push_back(value);
    }
    return is;
}
template <typename T1, typename T2>
std::istream& operator>>(std::istream& is, std::pair<T1, T2>& pa) {
    is >> pa.first >> pa.second;
    return is;
}

// Typedefs
#define Pair(typename) std::pair<typename, typename>
#define Vec(typename) std::vector<typename>
#define Arr(typename, count) std::array<typename, count>
#define Vec3(typename) Arr(typename, 3)
typedef signed char s8;
typedef unsigned char u8;
typedef long double ld;

// STL bullshit
// When really want to use, should add std::
#define next nextaerawer
#define prev prevawerawer
#define size sizewaeriwor
#define data dataaeraewra
#define hash hashdesrawer
#define move moveaerawer
#define x0 x0aerawerwe
#define x1 x1aesraewrew
#define y0 y0aeroiawera
#define y1 y1oiiajeroawe
#define left lefteaeraewr
#define right righteaerawer

using namespace std;

// Main segment

long long a[100001] = {};
long long b[100001] = {};
long long c[100001] = {};
long long s[100001] = {};
long long ans = 0;
long long n;

inline void msort(long long l, long long r) {
    if (l == r)
        return;
    long long mid = (l + r) >> 1;
    msort(l, mid);
    msort(mid + 1, r);
    long long i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (s[i] <= s[j])
            c[k++] = s[i++];
        else {
            c[k++] = s[j++];
            ans += (mid - i + 1);
        }
    }
    while (i <= mid)
        c[k++] = s[i++];
    while (j <= r)
        c[k++] = s[j++];
    for (i = l; i <= r; i++)
        s[i] = c[i];
}

long long f(long long x) {
    for (long long i = 1; i <= n; i++) {
        b[i] = (a[i] >= x ? 1 : -1);
    }
    s[0] = 0;
    for (long long i = 1; i <= n; i++) {
        s[i] = b[i] + s[i - 1];
    }
    ans = 0;
    msort(0, n);
    return (long long)n * (long long)(n - 1) / 2 + n - ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    long long maxv = 0, minv = 1e9;
    for (long long i = 1; i <= n; i++)
        cin >> a[i], maxv = max(maxv, a[i]), minv = min(minv, a[i]);
    long long total = (long long)n * (long long)(n - 1) / 2 + n;
    long long totalp = total % 2 ? total / 2 + 1 : total / 2;
    long long l, r, m;
    for (l = minv, r = maxv + 1; l + 1 < r; m = (l + r) / 2, f(m) < totalp ? r = m : l = m)
        ;
    cout << l << endl;
#ifdef LOCAL
    system("pause");
#endif
    return 0;
}
