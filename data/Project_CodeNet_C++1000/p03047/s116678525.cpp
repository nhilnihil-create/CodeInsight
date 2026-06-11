#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

using namespace std;

template <typename T> void output(T, int);
int gcd(int a, int b);

int main() {
    // source
    int n, k;
    cin >> n >> k;
    cout << n - k + 1 << endl;
    return 0;
}

template <typename T> void output(T a, int precision) {
    if (precision > 0) {
        cout << setprecision(precision) << a << "\n";
    } else {
        cout << a << "\n";
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
