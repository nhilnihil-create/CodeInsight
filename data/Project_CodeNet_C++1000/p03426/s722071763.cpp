#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int H, W, D; cin >> H >> W >> D;
    int N = H * W;
    vector<P> A(N+1);
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            int a; cin >> a;
            A[a] = make_pair(i, j);
        }
    }

    vector<int> x(N+1);
    for (int i = 1; i <= D; i++){
        int now = i;
        while(now+D <= N){
            P l = A[now];
            P r = A[now+D];
            int kyori = abs(l.first - r.first) + abs(l.second - r.second);
            x[now+D] = x[now] + kyori;
            now += D;
        }
    }

    int Q; cin >> Q;
    rep(i, Q){
        int L, R; cin >> L >> R;
        int ans = x[R] - x[L];
        cout << ans << endl;
    }

    return 0;
}