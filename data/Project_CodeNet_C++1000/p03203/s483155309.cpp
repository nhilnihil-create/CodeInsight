#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<int> a[200001];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i) {
        cin >> x >> y;
        --x, --y;
        a[x].push_back(y);
    }
    for(int i = 0; i < n; ++i)
        sort(a[i].begin(), a[i].end());
    x = 0, y = 0;
    for(int i = 0; i < n; ++i) {
        ++x;
        if(!a[x].empty() && a[x][0] <= y) {
            cout << i + 1;
            return 0;
        }
        auto d = upper_bound(a[x].begin(), a[x].end(), y);
        if(d == a[x].end() || *d > y + 1)
            ++y;
    }
    cout << n;
    return 0;
}
