#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, D;
    cin >> H >> W >> D;

    vector<int> x(H * W);
    vector<int> y(H * W);

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int A;
            cin >> A;
            A--;
            y[A] = i;
            x[A] = j;
        }
    }

    vector<int> a(H * W);

    for(int i = 0; i < H * W - D; i++) {
        a[i + D] = a[i] + abs(x[i] - x[i + D]) + abs(y[i] - y[i + D]);
    }

    int Q;
    cin >> Q;

    vector<int> ans(Q);

    for(int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        ans[i] = a[R] - a[L];
    }

    for(int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
}