#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)





int main() {
    ull n, X;
    cin >> n >> X;
    vector<ull> x(5 * n);
    REP(i, n){
        cin >> x[n - i];
    }
    REP(i, 5 * n - 1){
        x[i + 1] += x[i];
    }
    ull ans = numeric_limits<ull>::max();
    for(ull k = 1; k <= n; k++){
        ull sum = 0;
        for(ull i = 1; i <= n; i += k){
            ull t = (i % k == 0)? i / k : i / k + 1;
            sum += (t == 1)? 5 * (x[i + k - 1] - x[i - 1]) : (2 * t + 1) * (x[i + k - 1] - x[i - 1]);
        }
        ans = min(ans, (n + k) * X + sum);
    }
    cout << ans << endl;
}
