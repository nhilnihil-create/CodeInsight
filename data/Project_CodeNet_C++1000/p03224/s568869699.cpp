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

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll,ll> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int k;
    bool chk = false;
    for (k = 2; k * (k - 1) / 2 <= n; k++) {
        if (k * (k - 1) / 2 == n) {
            chk = true;
            break;
        }
    }
    if (!chk) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n" << k << "\n";
    vector<int> graph[k];
    int tmp = 1;
    rep (i, k) {
        repp (j, i + 1, k) {
            graph[i].push_back(tmp);
            graph[j].push_back(tmp);
            tmp++;
        }
    }
    rep (i, k) {
        cout << k - 1 << " ";
        for (int j : graph[i]) cout << j << " ";
        cout << "\n";
    }
    return 0;
}