#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
using Graph = V<V<int>>;
const int MOD =  1000000007;
const ll INF = 1LL << 60;


int main() {
    int n; cin >> n;
    V<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    V<int> sums;
    sums.push_back(h[0]);
    for(int i = 0; i < n - 1; i++){
        int tmp = h[i + 1] - h[i];
        if(0 < tmp) sums.push_back(tmp);
    }
    cout << accumulate(ALL(sums), 0) << endl;

    return 0;
}
