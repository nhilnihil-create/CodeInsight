#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)

int N, F[101][11], P[101][11];
#define INF INT_MAX/2

int main(){
   
   cin >> N;
    rep(i, 0, N) rep(j, 0, 10) cin >> F[i][j];
    rep(i, 0, N) rep(j, 0, 11) cin >> P[i][j];
 
    int ans = -INF;
    rep(msk, 1, 1 << 10) {
        int sm = 0;
        rep(i, 0, N) {
            int c = 0;
            rep(j, 0, 10) if (msk & (1 << j)) if (F[i][j]) c++;
            sm += P[i][c];
        }
        ans = max(ans, sm);
    }
    cout << ans << endl;
}