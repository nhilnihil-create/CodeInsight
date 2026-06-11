#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    int F[101][11];
    rep(i, N){
        rep(j, 10){
            cin >> F[i][j];
        }
    }
    int P[101][11];
    rep(i, N){
        rep(j, 11){
            cin >> P[i][j];
        }
    }
    int ans = -1001001001;
    for (int i = 1; i < 1<<10; i++){
        int now = 0;
        rep(j, N){
            int cnt = 0;
            rep(k, 10){
                if(i>>k&1 && F[j][k] == 1){
                    cnt++;
                }
            }
            now += P[j][cnt];
            //cout << j << " " << cnt << " " << now << endl;
        }
        ans = max(ans, now);
    }

    cout << ans << endl;

    return 0;
}