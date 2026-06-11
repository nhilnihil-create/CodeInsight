#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, C;
    cin >> N >> C;

    vector<vector<int> > D(C, vector<int>(C));

    for(int i = 0; i < C; i++) {
        for(int j = 0; j < C; j++) {
            cin >> D[i][j];
        }
    }

    vector<vector<int> > c(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    vector<vector<int> > S(3, vector<int>(C));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            S[(j + i) % 3][c[i][j]]++;
        }
    }

    int ans = 1000000000;

    for(int i = 0; i < C; i++) {
        for(int j = 0; j < C; j++) {
            if(i == j) continue;
            for(int k = 0; k < C; k++) {
                if(i == k || j == k) continue;
                int c = 0;
                for(int m = 0; m < C; m++) {
                    c += S[0][m] * D[m][i];
                    c += S[1][m] * D[m][j];
                    c += S[2][m] * D[m][k];
                }
                ans = min(ans, c);
            }
        }
    }

    cout << ans << endl;
}