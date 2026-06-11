#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
 freopen("input","r",stdin);
 freopen("output","w",stdout);
 */

int cal(ll num) {
    int ans = 0;
    while (num > 0) {
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll r = 10;
    vector<pair<ll, ll>> R;
    for (int i = 1;i <= 9;i++) R.push_back(make_pair(i, i));
    while (r < 1E15) {
        for (int i = 0;i <= 135;i++) {
            ll num = r * (i + 1) - 1;
            ll d = cal(num);
            if (num < 1E16) {
                R.push_back(make_pair(num, d));
            }
        }
        r *= 10;
    }
    sort(R.begin(), R.end());
    set<ll> sol;
    for (int i = 0;i < R.size();i++) {
        bool ok = true;
        for (int j = i + 1;j < R.size();j++) {
            if (R[i].first * R[j].second > R[i].second * R[j].first) ok = false;
        }
        if (ok) sol.insert(R[i].first);
    }
    int K;
    cin >> K;
    auto it = sol.begin();
    for (int i = 0;i < K;i++) {
        cout << *it << endl;
        it++;
    }
    return 0;
}
