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
    int N;
    cin >> N;
    vector<int> D(N);
    rep(i, N) { cin >> D[i]; }
    int M;
    cin >> M;
    vector<int> T(M);
    rep(i, M) { cin >> T[i]; }
    map<int, int> mp;
    rep(i, N) { mp[D[i]]++; }
    rep(i, M) {
        if(mp[T[i]] == 0) {
            cout << "NO" << endl;
            return 0;
        }
        mp[T[i]]--;
    }
    cout << "YES" << endl;
    return 0;
}