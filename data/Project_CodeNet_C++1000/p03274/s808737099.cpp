#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    for (int i=0;i<N;i++) cin >> x[i];
    int ans = INF;
    for (int i=0;i<N-K+1;i++){
        int p = x[i+K-1] - x[i] + abs(x[i+K-1]);
        int q = x[i+K-1] - x[i] + abs(x[i]);
        int r = min(p,q);
        ans = min(ans, r);
    }
    cout << ans << "\n";
}