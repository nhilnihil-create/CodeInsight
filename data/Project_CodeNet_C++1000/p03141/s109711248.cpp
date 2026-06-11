#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    using pii = pair<ll, ll>;
    vector<pii> AB(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        AB[i] = MP(a, b);
    }
    sort(All(AB), [](const pii &a, const pii &b) {
        return a.first + a.second > b.first + b.second;
    });
    ll T = 0, A = 0;
    rep(i, N) {
        if(i % 2 == 0)
            T += AB[i].first;
        else
            A += AB[i].second;
    }
    cout << T - A << endl;
    return 0;
}