#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<string>S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        bool ok = true;
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(S[j][k] != S[(k+i)%N][(j+N-i)%N]) {
                    ok = false;
                }
            }
        }
        if(ok) {
            ans++;
        }
    }
    cout << ans*N << endl;
}
