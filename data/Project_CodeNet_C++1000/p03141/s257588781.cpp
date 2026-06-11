#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using WGraph = std::vector<std::vector<std::pair<int, long long>>>;
using ll = long long;
using namespace std;
 
int main() {
    int n = 0;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i=0; i<n; i++) { 
        cin >> a.at(i) >> b.at(i);
    }
    vector<pair<ll, int>> sum(n);
    for (int i=0; i<n; i++) {
        sum.at(i) = make_pair(a.at(i) + b.at(i), i);
    } 
    sort(sum.begin(), sum.end());
    reverse(sum.begin(), sum.end());
    ll ans = 0;
    for (int i=0; i<n; i++) {
        int cur = sum.at(i).second;
        if (i%2 == 0) {
            ans += a.at(cur);
        } else {
            ans -= b.at(cur);
        }
    }
    cout << ans << endl;
    return 0;
}
