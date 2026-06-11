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
    vector<vector<int>> G(N);
    vector<int> A(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A.rbegin(), A.rend());
    vector<int> res(N);
    queue<int> que;

    int ptr = 0;
    que.push(0);

    vector<int> used(N);

    while(!que.empty()) {
        int v = que.front();
        used[v] = 1;
        res[v] = A[ptr];
        ptr++;
        que.pop();
        for(int nv : G[v]) {
            if(used[nv])
                continue;
            que.push(nv);
        }
    }
    cout << sum - A[0] << endl;
    rep(i, N) cout << res[i] << " ";
    cout << endl;
    return 0;
}