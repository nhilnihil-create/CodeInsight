#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    char S[N][N];
    char S2[N][N];
    rep(i, N){
        rep(j, N){
            cin >> S[i][j];
        }
    }

    int ans = 0;
    rep(k, N){
        rep(i, N){
            rep(j, N){
                int x = (i+k) % N;
                S2[x][j] = S[i][j];
            }
        }

        bool ok = true;
        rep(i, N){
            for (int j = i+1; j < N; j++){
                if(S2[i][j] != S2[j][i]){
                    ok = false;
                    break;
                }
            }
            if(!ok)break;
        }
        if(ok)ans++;
    }

    cout << ans * N << endl;

    return 0;
}