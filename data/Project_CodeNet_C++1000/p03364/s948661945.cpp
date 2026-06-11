#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using ll = long long;
#define int long long
int n;
char board[310][310];
bool check(int a, int b){
    char board2[310][310];
    rep(i,n)rep(j,n) board2[(i+a)%n][(j+b)%n] = board[i][j];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++) if(board2[i][j]!=board2[j][i]) return false;
    }
    return true;
}
signed main(void){
    cin>>n;
    rep(i,n) rep(j,n) cin>>board[i][j];
    int ans = 0;
    rep(i,n){
        bool ok;
        ok = check(0,i);
        if(ok) ans+=n;
    }
    cout<<ans<<endl;
}
