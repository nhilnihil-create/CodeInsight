#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())

int main(){
    int c[3][3];

    rep(i,3){
        rep(j,3){
            cin >> c[i][j];
        }
    }

    int x[3],y[3];
    x[0] = 0;

    rep(i,3)    y[i] = c[0][i] - x[0];
    rep(i,3)    x[i] = c[i][0] - y[0];

    bool good(true);

    rep(i,3){
        rep(j,3){
            if(x[i]+y[j]!=c[i][j])
                good = false;
        }
    }

    if(good)
        puts("Yes");
    else
        puts("No");

    return 0;
}