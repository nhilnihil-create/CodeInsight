#include <bits/stdc++.h>
using namespace std;
using cpx = complex<double>;
using namespace std::literals;
using Int = long long;
using Double = long double;
#ifdef __GNUG__
#define _GLIBCXX_DEBUG
#endif
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define F first
#define S second
#define perm(c)   \
    sort(ALL(c)); \
    for (bool c##p = 1; c##p; c##p = next_permutation(ALL(c)))
vector<Int> IntsIn(int n) {
    auto v = vector<Int>(0);
    for (int i = 0; i < n; i++) {
        Int a;
        cin >> a;
        v.push_back(a);
    }
    return v;
}
template <typename T>
void Puts(T x) {
    cout << x << endl;
}
void setPrecision(int num = 20) {
    std::cout << std::fixed << std::setprecision(num);
}
template <typename T>
T Max(T a) {
    return a;
}
template <typename T, typename... Args>
T Max(T a, Args... args) {
    return std::max(Max(args...), a);
}
template <typename T>
T Min(T a) {
    return a;
}
template <typename T, typename... Args>
T Min(T a, Args... args) {
    return std::min(Min(args...), a);
}
template <typename T>
bool vector_contains(std::vector<T> vec, T value) {
    return (std::distance(vec.begin(), std::find(vec.begin(), vec.end(), value)) != vec.size());
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}
int main() {
    int n;
    cin >> n;
    auto v = vector<pair<Int, Int>>(0);
    rep(i, n) {
        Int a, b;
        cin >> a >> b;
        v.PB(MP(a, b));
    }
    sort(ALL(v), [](const auto &t1, const auto &t2) {
        return (t1.F + t1.S) > (t2.F + t2.S);
    });
    Int ans = 0;
    rep(i, n) {
        if (i % 2 == 0) {
            ans += v[i].F;
        } else {
            ans -= v[i].S;
        }
    }
    Puts(ans);
}
