#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPD(i,N) for(int i=0; i<int(N); --i)
#define PB push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //配列の最大のrenge



int main() {
    int N; cin >> N;
    vector<vector<int>> G(2, vector<int>(N));
    vector<int> G2(N);
    REP(i,2)REP(j,N) cin >> G[i][j];
    
    REP(i,N) {
        int sum = 0;
        FOR(j,0,i+1) sum += G[0][j];
        FOR(j,i,N) sum += G[1][j];
        G2[i] = sum;
    }

    int max = *max_element(ALL(G2));
    cout << max;
}
