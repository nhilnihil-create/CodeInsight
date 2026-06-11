#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

#define for1(n) for (int i = 0 ; i < n ; i++)
#define for2(n) for (int j = 0 ; j < n ; j++)
#define for1l(n) for (ll i = 0 ; i < n ; i++)
#define for2l(n) for (ll j = 0 ; j < n ; j++)

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int x[n], y[n], h[n];
    for1(n) cin >> x[i] >> y[i] >> h[i];
    for1(n) if (h[i]) swap(x[0], x[i]), swap(y[0], y[i]), swap(h[0], h[i]);
    for (int i = 0 ; i <= 100 ; i++) {
        for (int j = 0 ; j <= 100 ; j++) {
            int a = abs(i - x[0]) + abs(j - y[0]) + h[0];
            bool w = 0;
            for (int k = 1 ; k < n ; k++) {
                if (max(0, a - abs(i - x[k]) - abs(j - y[k])) != h[k]) w = 1;
            }
            if (w == 0) {
                cout << i << ' ' << j << ' ' << a;
                return 0;
            }
        }
    }
}