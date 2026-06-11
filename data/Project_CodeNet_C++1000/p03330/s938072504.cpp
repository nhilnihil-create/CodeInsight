#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(int)(n); i++)
int main(){
int N, C, n=3, ans=1e9; cin >> N >> C; int D[C][C], c[N][N], moto[n][C]={};
REP(i, C){ REP(j, C){ cin >> D[i][j]; } }
REP(i, N){ REP(j, N){ cin >> c[i][j]; moto[((i+1)+(j+1))%3][c[i][j]-1]++; } }
REP(i, C){ REP(j, C){ if(i==j){ continue; } REP(k, C){ if(i==k||j==k){ continue; }
 int now=0;
 REP(x, C){ now=now+moto[0][x]*D[x][i]+moto[1][x]*D[x][j]+moto[2][x]*D[x][k]; } 
 ans=min(ans, now);
} } }
cout << ans << "\n";
}