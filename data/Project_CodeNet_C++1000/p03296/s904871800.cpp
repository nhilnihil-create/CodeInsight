#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

#define INF 1e18
#define int long long

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int i = 0;
    while(i < n) {
        int cnt = 0;
        int j = i;
        while(a[i] == a[j] && j < n) {
            cnt++;
            j++;
        }
        ans += cnt / 2;
        i = j;
    }

    cout << ans << endl;
    return 0;
}
