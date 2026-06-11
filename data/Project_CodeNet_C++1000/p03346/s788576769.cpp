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
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    vector<int> order(N);
    rep(i, N) { order[P[i] - 1] = i; }
    int len = 1;
    int now = 1;
    for(int i = 0; i < N - 1; i++) {
        if(order[i] < order[i + 1])
            now++;
        else
            now = 1;
        len = max(len, now);
    }
    cout << N - len << endl;
    return 0;
}