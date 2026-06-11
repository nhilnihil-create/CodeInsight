#include <bits/stdc++.h>
 
using namespace std;

#define INF 1e9
#define LINF 1e18
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define VPII vector<PII>

int N;
VI H;
VI cost;

int dp(int n){
    if(cost[n] != -1){
        return cost[n];
    }
    return cost[n] = min(dp(n-1)+abs(H[n]-H[n-1]),dp(n-2)+abs(H[n]-H[n-2]));
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(11);
    cerr << fixed << setprecision(6);

    cin >> N;
    H.assign(N,-1);
    cost.assign(N,-1);
    R(i,N) cin >> H[i];
    cost[0] = 0;
    cost[1] = abs(H[0]-H[1]); 
    dp(N-1);
    cout << to_string(cost[N-1]) << endl;
}
