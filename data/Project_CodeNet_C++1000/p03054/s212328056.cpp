// #define CPP_IO

#pragma region

#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T>;

#define f first
#define s second

#ifdef LOCAL
#define debug cout
#define debugf(format, ...) printf(format, ##__VA_ARGS__)
#else
#define debug \
    if (0) cout
#define debugf(format, ...) 42
#endif

#define DUMP(a) debug << #a " = " << (a) << "\n";
#define DUMP2(a, b) debug << #a " = " << (a) << " " #b " = " << (b) << "\n";
#define DUMP3(a, b, c) debug << #a " = " << (a) << " " #b " = " << (b) << " " #c " = " << (c) << "\n";
#define DUMP4(a, b, c, d) debug << #a " = " << (a) << " " #b " = " << (b) << " " #c " = " << (c) << " " #d " = " << (d) << "\n";

template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "[ ";
    for (auto e : v) os << e << " ";
    return os << "]";
}

template <typename T, typename V>
ostream& operator<<(ostream& os, set<T, V> v) {
    os << "{ ";
    for (auto e : v) os << e << " ";
    return os << "}";
}

template <typename T, typename V, typename S>
ostream& operator<<(ostream& os, map<T, V, S> v) {
    os << "{ ";
    for (auto e : v) os << e << " ";
    return os << "}";
}

template <typename T, typename V>
ostream& operator<<(ostream& os, pair<T, V> x) {
    return os << "( " << x.first << ", " << x.second << " )";
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& e : v) is >> e;
    return is;
}

template <typename T, typename V>
istream& operator>>(istream& is, pair<T, V>& x) {
    return is >> x.first >> x.second;
}

void solve();

int main() {
#ifdef LOCAL
    freopen("data.txt", "r", stdin);
#else
#ifdef CPP_IO
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
#endif
    solve();
}

#pragma endregion

void solve() {
    int numR, numC, n;
    int startR, startC;
    string s, t;
    cin >> numR >> numC >> n >> startR >> startC >> s >> t;
    int L = startC, R = startC, U = startR, D = startR;
    for (int i = 0; i < n; ++i) {
        // printf("i = %d L = %d R = %d U = %d D = %d\n", i, L, R, U, D);
        if (s[i] == 'U') {
            --U;
        } else if (s[i] == 'D') {
            ++D;
        } else if (s[i] == 'L') {
            --L;
        } else {
            ++R;
        }
        if (U < 1 || D > numR || L < 1 || R > numC) {
            cout << "NO\n";
            return;
        }
        if (t[i] == 'U') {
            --D;
        } else if (t[i] == 'D') {
            ++U;
        } else if (t[i] == 'L') {
            --R;
        } else {
            ++L;
        }
        if (U < 1) U = 1;
        if (U > numR) U = numR;
        if (D < 1) D = 1;
        if (D > numR) D = numR;
        if (L < 1) L = 1;
        if (L > numC) L = numC;
        if (R < 1) R = 1;
        if (R > numC) R = numC;
    }
    cout << "YES\n";
}