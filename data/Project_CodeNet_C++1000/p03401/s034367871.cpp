#include <iostream>
#include <vector>
#include <numeric>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n + 2, 0);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> cost(n + 1, 0);
    rep(i, n + 1) cost[i] = abs(a[i + 1] - a[i]);

    ll total = accumulate(all(cost), 0ll); 
    for (int i = 1; i <= n; ++i) {
        cout << (total - cost[i - 1] - cost[i] + abs(a[i - 1] - a[i + 1])) << endl;
    }
}