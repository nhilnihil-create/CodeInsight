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

int main() {
    int s;
    cin >> s;
    int i = 1;
    set<int> a;
    int t = s;
    a.insert(s);
    while (true) {
        i++;
        if (t % 2) {
            t = 3 * t + 1;
            if (a.find(t) != a.end())
                break;
            a.insert(t);
        }
        else {
            t /= 2;
            if (a.find(t) != a.end())
                break;
            a.insert(t);
        }
    }
    cout << i << endl;
}