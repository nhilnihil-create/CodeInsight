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
    ll n = 0, k = 0;
    cin >> n >> k;
    vector<pair<ll, int>> sushi(n);
    for (ll i=0; i<n; i++) {
        cin >> sushi.at(i).second >> sushi.at(i).first;
    }
    sort(sushi.begin(), sushi.end(), greater<pair<ll, int>>());
    vector<int> check(n+1, 0);
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll point = 0;
    ll kind = 0;
    for (int i=0; i<k; i++) {
        point += sushi.at(i).first;
        check.at(sushi.at(i).second)++;
        if (check.at(sushi.at(i).second) > 1) {
            que.push(sushi.at(i).first);
        }
        else {
            kind++;
        }
    }
    ll ans = point + kind * kind;
    for (int i=k; i<n; i++) {
        if (check.at(sushi.at(i).second) > 0) {
            continue;
        }
        if (que.empty()) {
            break;
        }
        ll tmp = que.top(); que.pop();
        point += sushi.at(i).first - tmp;
        check.at(sushi.at(i).second)++;
        kind++;
        ans = max(ans, point + kind * kind);
    }
    cout << ans << endl;
    return 0;
}
 