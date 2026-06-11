#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
// template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int code (string s) {
    if (s == "Male") return 1;
    else if (s == "Female") return 2;
    else return 0;
}
int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s;
    vector<int> state(n);
    // 1: male 2: female
    printf("0\n"); fflush(stdout);
    cin >> s; state[0] = code(s); if (!state[0]) return 0;
    printf("%d\n", n/2); fflush(stdout);
    cin >> s; state[n/2] = code(s); if (!state[n/2]) return 0;
    int l, r;
    if ((n/2) % 2 == 0 ^ state[n/2] == state[0]) {
        l = 0; r = n/2;
    } else {
        l = n/2; r = n;
    }
    while (r - l > 1) {
        int m = (r + l) / 2;
        printf("%d\n", m); fflush(stdout);
        cin >> s; state[m] = code(s); if (!state[m]) return 0;
        if ((m - l) % 2 == 0 ^ state[m] == state[l]) r = m;
        else l = m;
    }
    return 0;
}