#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<55)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

lli dToC[3][600];
lli d[40][40];
lli c[600][600];

int main(){

    lli N,C;
    cin>>N>>C;

    REP(i,0,C)REP(j,0,C)cin>>d[i][j];
    REP(i,0,N)REP(j,0,N){
        cin>>c[i][j];
        c[i][j]--;
    }

    REP(i,0,C){
        lli cSum[3]={0,0,0};

        REP(j,0,N)REP(k,0,N){
            cSum[(j+k)%3] += d[c[j][k]][i];
        }

        REP(j,0,3)dToC[j][i] = cSum[j];
    }

    lli ans = INF;
    REP(i,0,C)REP(j,0,C){
        if(i==j)continue;
        REP(k,0,C){
            if(i==k || j==k)continue;
            ans = min(ans,dToC[0][i]+dToC[1][j]+dToC[2][k]);
        }
    }
    cout<<ans<<endl;

    return 0;
}
