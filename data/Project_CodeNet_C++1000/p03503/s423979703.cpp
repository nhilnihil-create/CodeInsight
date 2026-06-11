#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
    int n;
    cin >> n;
    int F[n][10];
    rep(i,n)rep(j,10) cin >> F[i][j];
    int P[n][11];
    rep(i,n)rep(j,11) cin >> P[i][j];

    int ans = -1e9;
    for (int i=1; i<(1<<10); i++){
        int index = 0;
        rep(j,n){
            int cnt = 0;
            rep(k,10){
                if (F[j][9-k] & (i>>k)) cnt++;
            }
            index += P[j][cnt];
            //printf("ans:%d index:%d cnt:%d\n", ans, index, cnt);
        }
        ans = max(ans, index);
    }

    cout << ans << endl;
    return 0;
}
