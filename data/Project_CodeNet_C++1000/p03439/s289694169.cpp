#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;
using P = pair<char, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    int n;
    cin >> n;

    int ok = 0, ng = n;
    cout << 0 << endl;
    string s0, s;
    cin >> s0;
    if(s0[0] == 'V') {
        return 0;
    }

    while(ng-ok > 1) {
        int mid = (ng+ok)/2;
        cout << mid << endl;
        cin >> s;
        if(s[0] == 'V') {
            return 0;
        }
        if(mid % 2) {
            if(s0[0] != s[0]) {
                ok = mid;
            } else {
                ng = mid;
            }
        } else {
            if(s0[0] != s[0]) {
                ng = mid;
            } else {
                ok = mid;
            }
        }
    }

    return 0;

}