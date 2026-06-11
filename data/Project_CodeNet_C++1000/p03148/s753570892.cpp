#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int N,K;
ll t[100010];
ll d[100010];

int main ()
{
    cin >> N >> K;
    REP(i,N) cin >> t[i] >> d[i];

    vector < pair < ll, ll > > ord;
    REP(i,N) ord.push_back(make_pair(d[i], i));
    sort(ord.begin(), ord.end());
    reverse(ord.begin(), ord.end());

    ll sum = 0;
    vector < ll > cnd;
    reversed_priority_queue < pair < ll, ll > > que1;
    priority_queue < pair < ll, ll > > que2;
    bool used[100010] = {};
    ll x2 = 0;
    REP(i,K) {
        ll idx = ord[i].second;
        ll del = ord[i].first;
        ll tt = t[idx];
        if (!used[tt]) {
            used[tt] = true;
            x2++;
        } else {
            que1.push(make_pair(d[idx], t[idx]));
        }
        sum += del;
    }
    for (int i = K; i < N; i++) {
        ll idx = ord[i].second;
        ll tt = t[idx];
        if (!used[tt]) {
            used[tt] = true;
            que2.push(make_pair(d[idx], t[idx]));
        }
    }

    cnd.push_back(sum + x2 * x2);
    while ((!que1.empty()) && (!que2.empty())) {
        sum -= que1.top().first;
        sum += que2.top().first;
        que1.pop();
        que2.pop();
        x2++;
        cnd.push_back(sum + x2 * x2);
    }

    ll ans = 0;
    REP(i,cnd.size()) {
        ans = max(ans, cnd[i]);
    }

    cout << ans << endl;

    return 0;
}
