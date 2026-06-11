#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    cin >> N >> K;
    vector<int>h(N);
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }
    int ans = INF;
    sort(h.begin(),h.end());
    for(int i = 0; i < N-K+1; i++) {
        ans = min(ans,h[i+K-1]-h[i]);
    }
    cout << ans << endl;
}
