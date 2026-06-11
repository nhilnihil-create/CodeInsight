#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define LL long long 
#define FOR(i,l,r) for(int i = l; i <= r; ++i)

const LL oo = 1e18;

LL A,B;
int C[5001],N;
LL F[5001][5001];

void minimize(LL &x,LL y){
    x = min(x,y);
}
void update(int i,int j){
    if(C[i + 1] < C[j]) minimize(F[i + 1][j],F[i][j] + B);
    else{
        minimize(F[i + 1][i + 1],F[i][j]);
        minimize(F[i + 1][j],F[i][j] + A);
    }
}
int main(){

    cin >> N >> A >> B;
    FOR(i,1,N) cin >> C[i];

    FOR(i,1,N) FOR(j,0,i) F[i][j] = oo;

    update(0,0);
    FOR(i,1,N - 1) FOR(j,0,i) if(F[i][j] < oo) update(i,j);

    LL res = oo;
    FOR(i,1,N) res = min(res,F[N][i]);

    cout << res;
    return 0;
}