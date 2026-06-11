#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    string s;
    cin >> s;
    
    s = "0" + s;
    string t = s;
    reverse(ALL(t));
    if (s != t) {
        cout << -1 << "\n";
    } else {
        if (s[1] == '0') {
            cout << -1 << "\n";
        } else {
            int k = 0;
            for (int i = 1; i < SZ(s) - 1; ++i) {
                if (s[i] == '0') {
                    cout << k + 1 << " " << i + 1 << "\n";
                } else {
                    cout << k + 1 << " " << i + 1 << "\n";
                    k = i;
                }
            }
        }
    }
    
    return 0;
}
