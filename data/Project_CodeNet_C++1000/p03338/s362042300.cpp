#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

signed main() {
    int n;
    string s;
    cin >> n >> s;
    int m = 0;
    for (int i = 1; i < n; i++) {
        set<char> a;
        set<char> b;
        for (int j = 0; j < i; j++)
            a.insert(s[j]);
        for (int j = i; j < n; j++)
            b.insert(s[j]);
        int c = 0;
        for (auto it = a.begin(); it != a.end(); it++) {
            if (b.find(*it) != b.end())
                c++;
        }
        chmax(m, c);
    }
    cout << m << endl;
}