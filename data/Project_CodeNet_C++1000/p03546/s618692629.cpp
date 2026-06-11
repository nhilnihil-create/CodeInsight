#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    vector<vector<int> > c(10, vector<int>(10));

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            cin >> c[i][j];

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                c[j][k] = min(c[j][k], c[j][i] + c[i][k]);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int A;
            cin >> A;
            if(A == -1) continue;
            ans += c[A][1];
        }
    }

    cout << ans << endl;
}