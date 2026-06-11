#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int H,W;
    cin >> H >> W;
    int C[10][10];
    rep(i,10)rep(j,10){
        cin >> C[i][j];
    }
    rep(k,10)rep(i,10)rep(j,10){
        C[i][j] = min(C[i][j],C[i][k] + C[k][j]);
    }
    ll ans = 0;
    rep(h,H)rep(w,W){
        int num;
        cin >> num;
        if(num!=-1) ans += C[num][1]; 
    }
    cout << ans << endl;
    return 0;
}