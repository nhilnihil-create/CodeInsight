#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<int, int>
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORU(i, a, b, s) for(int i = a; i < b; i += s)
#define FORD(i, a, b, s) for(int i = a; i > b; i -= s)
#define endl "\n"

ll INF = 2e18;
ll MOD = 1e9 + 7;
int i, j, k;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> cnt(M + 1);
    FOR(i, N) {
        int K;
        cin >> K;
        FOR(j, K) {
            int t;
            cin >> t;
            cnt[t] += 1;
        }
    }

    int ans = 0;
    FOR(i, M + 1) {
        if(cnt[i] == N) {
            ans += 1;
        }
    }

    cout << ans << endl;
}