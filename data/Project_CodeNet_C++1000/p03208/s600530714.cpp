#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, K; cin >> N >> K;
    vector<int> h(N);
    rep(i, N){
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    
    int ans = 1001001001;
    for (int i = 0; K-1+i < N; i++){
        int x = h[K-1+i] - h[i];
        ans = min(ans, x);
    }

    cout << ans << endl;

    return 0;
}