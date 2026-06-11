/* ---------- STL Libraries ---------- */

// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* ---------- Namespace ---------- */

using namespace std;

/* ---------- Type Abbreviation ---------- */

template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

using ll = long long;

#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple

/* ---------- conversion ---------- */

#define INT(c) static_cast<int>(c)
#define CHAR(n) static_cast<char>(n)
#define LL(n) static_cast<ll>(n)
#define DOUBLE(n) static_cast<double>(n)

/* ---------- container ---------- */

#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) (LL((v).size()))

#define FIND(v, k) (v).find(k) != (v).end()
#define VFIND(v, k) find(ALL(v), k) != (v).end()

#define gsort(b, e) sort(b, e, greater<decltype(*b)>())

/* ----------- debug ---------- */

template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> v) {
    os << "[";
    for (auto vv : v)
        os << vv << ",";
    return os << "]";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "(" << p.fst << "," << p.snd << ")";
}

/* ---------- Constants ---------- */

// const ll MOD = 1e9 + 7;
// const int INF = 1 << 25;
// const ll INF = 1LL << 50;
// const double PI = acos(-1);
// const double EPS = 1e-10;
// mt19937 mert(LL(time(0)));

/* ---------- Short Functions ---------- */

template <typename T>
T sq(T a) {
    return a * a;
}

template <typename T>
T gcd(T a, T b) {
    if (a > b) return gcd(b, a);
    return a == 0 ? b : gcd(b % a, a);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b /* % MOD */;
    if (n % 2 == 0) {
        return mypow(b * b /* % MOD */, n / 2);
    } else {
        return mypow(b, n - 1) * b /* % MOD */;
    }
}

ll pcnt(ll b) {
    return __builtin_popcountll(b);
}

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */

int main() {
    int N;
    cin >> N;

    ll X[N], Y[N];
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    int parity = (X[0] + Y[0] + (1LL << 35)) % 2;
    for (int i = 1; i < N; ++i) {
        if ((X[i] + Y[i] + (1LL << 35)) % 2 != parity) {
            cout << -1 << endl;
            return 0;
        }
    }

    // 偶数の場合は最後にLくっつけて奇数に変換する
    if (parity == 0) {
        for (int i = 0; i < N; ++i) {
            ++X[i];
        }
    }

    // 実際はd[k] = 2^kで-d[k]かd[k]を選択だが,
    // 下駄を履かせてd[k] = 2^(k+1)で0かd[k]を選択する
    // さらに2で割ることで0か2^kを選択するようにする
    cout << 36 - parity << endl;
    for (int k = 0; k < 35; ++k) {
        cout << (1LL << k) << " ";
    }
    if (parity == 0) cout << 1;
    cout << endl;

    // (X, Y) -> (X - Y, X + Y)に変換
    // さらに2^35-1だけ下駄を履かせ, 2で割る
    for (int i = 0; i < N; ++i) {
        ll tmp = X[i];
        X[i] -= Y[i];
        Y[i] += tmp;

        X[i] += (1LL << 35) - 1;
        X[i] /= 2;
        Y[i] += (1LL << 35) - 1;
        Y[i] /= 2;
    }

    // 各指示に対応する変化
    // L -> -X, -Y  R -> +X, +Y
    // U -> -X, +Y  D -> +X, -Y

    string order = "LDUR";
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < 35; ++k) {
            int kind = 0;
            if ((X[i] >> k) & 1) kind += 1;
            if ((Y[i] >> k) & 1) kind += 2;
            cout << order[kind];
        }
        if (parity == 0) cout << "L";
        cout << endl;
    }
    return 0;
}
