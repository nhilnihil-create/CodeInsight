#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstdint>
#include <cctype>
#include <numeric>
#include <bitset>
#include <functional>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};
constexpr int A_MAX = 200000;

int main() {
    string s,t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    int succeeded_index = -1;
    for(int i=0;i<n;++i) {
        bool ok = true;
        for(int j=0;j<m;++j) {
            ok &= (s[i+j] == '?' || s[i+j] == t[j]);
        }
        if(ok) {
            succeeded_index = i;
        }
    }

    if(succeeded_index == -1) {
        cout << "UNRESTORABLE\n";
        return 0;
    }
    for(int i=0;i<n;++i) {
        if(succeeded_index <= i && i < succeeded_index+m) {
            cout << t[i-succeeded_index];
        } else if(s[i] == '?') {
            cout << 'a';
        } else {
            cout << s[i];
        }
    }
}
