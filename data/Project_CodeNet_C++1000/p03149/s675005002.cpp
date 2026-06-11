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
#include <type_traits>
using namespace std;

#define INF 1e18
#define int long long

signed main() {
    vector<int> v(4);
    for(int i = 0; i < 4; i++) cin >> v[i];

    map<int, int> mp;
    mp[1] = 0;
    mp[9] = 0;
    mp[7] = 0;
    mp[4] = 0;
    for(int i = 0; i < 4; i++) {
        mp[v[i]]++;
    }

    if(mp[1] > 0 && mp[9] > 0 && mp[7] > 0 && mp[4] > 0) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}
