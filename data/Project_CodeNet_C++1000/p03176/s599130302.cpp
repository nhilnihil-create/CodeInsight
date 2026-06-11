// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 1 << 18;

class Node {
public:
    ll max;
    int l, r;

    Node() : max(-LINF), l(-1), r(-1) {}

    Node(ll val, int l, int r) : max(val), l(l), r(r) {}

    Node operator+(const Node& other) const {
        return Node(std::max(max, other.max), l, other.r);
    }
};

Node tree[2 * N];

void build() {
    for (int i = 0; i < N; ++i) {
        tree[i + N] = Node(0, i, i + 1);
    }
    for (int i = N - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

Node get(int v, int l, int r) {
    if (tree[v].r <= l || r <= tree[v].l) {
        return Node();
    }
    if (l <= tree[v].l && tree[v].r <= r) {
        return tree[v];
    }
    return get(v * 2, l, r) + get(v * 2 + 1, l, r);
}

void upd(int pos, ll newVal) {
    pos += N;
    tree[pos].max = newVal;
    pos /= 2;

    while (pos > 0) {
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
        pos /= 2;
    }
}

int h[N], a[N];

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    build();

    for (int i = 0; i < n; ++i) {
        Node val = get(1, 0, h[i]);
        upd(h[i], val.max + a[i]);
    }

    printf("%lld\n", get(1, 0, N).max);
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}
