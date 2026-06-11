#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdint>
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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) { cin >> A[i]; }
    rep(i, N) { cin >> B[i]; }
    vector<ll> over;
    ll shortage = 0;
    ll lessCnt = 0;
    rep(i, N) {
        ll a = A[i] - B[i];
        if(a < 0) {
            shortage += a * (-1);
            lessCnt++;
        } else {
            over.pb(a);
        }
    }
    sort(over.rbegin(), over.rend());
    vector<ll> sum(over.size() + 1);
    rep(i, over.size()) { sum[i + 1] = over[i] + sum[i]; }
    for(int i = 0; i <= sum.size(); i++) {
        if(sum[i] >= shortage) {
            cout << lessCnt + i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}