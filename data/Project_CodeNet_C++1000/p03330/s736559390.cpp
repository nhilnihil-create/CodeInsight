#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int N, C, D[35][35], c[510][510];
    cin >> N >> C;
    rep1(i,C) rep1(j,C) cin >> D[i][j];
    rep1(i,N) rep1(j,N) cin >> c[i][j];

    map<int,int> colors0, colors1, colors2;
    rep1(i,N) rep1(j,N){
        if((i+j)%3 == 0) colors0[c[i][j]]++;
        if((i+j)%3 == 1) colors1[c[i][j]]++;
        if((i+j)%3 == 2) colors2[c[i][j]]++;
    }

    Int ans = 1e16;
    rep1(c1,C)rep1(c2, C) rep1(c3,C){
        if(c1 == c2 || c2 == c3 || c3 == c1) continue;

        Int cur = 0;
        for(pair<int,int> x: colors0)
            cur += x.second * D[x.first][c1];
        
        for(pair<int,int> x: colors1)
            cur += x.second * D[x.first][c2];
        
        for(pair<int,int> x: colors2)
            cur += x.second * D[x.first][c3];

        ans = min(ans, cur);
    }

    cout << ans << endl;
}