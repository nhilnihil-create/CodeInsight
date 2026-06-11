#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()

int main() {
    int n, a[100000], max_a = 0, center = 0;
    cin >> n;
    REP(i, n) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    REP(i, n) {
        if (abs(max_a / 2 - a[i]) < abs(max_a / 2 - center))
            center = a[i];
    }
    cout << max_a << " " << center << endl;
    
    return 0;
}