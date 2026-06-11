#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    vector<int> cnt(4);
    rep(i, 3) {
        int a, b;
        cin >> a >> b;
        cnt[--a]++;
        cnt[--b]++;
    }
    sort(All(cnt));
    if(cnt[0] == 1 && cnt[1] == 1 && cnt[2] == 2 && cnt[3] == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}