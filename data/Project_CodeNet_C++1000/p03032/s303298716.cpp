#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll DP[200][200][100];
ll V[100];

int main(){
    ll N, K;
    cin >> N >> K;
    REP(i,N){
        cin >> V[i];
    }

    REP(i,200) REP(j,100) REP(k,100)
        DP[i][j][k] = -1e17;

    const ll a = 1;
    DP[0][0][a+N-1] = 0;
    REP(i,K){
        REP(l,N){
            REPi(r,l,N){
                chmax(DP[i+1][l][a+r],   DP[i][l][a+r]);
                chmax(DP[i+1][l+1][a+r], DP[i][l][a+r] + V[l]);
                chmax(DP[i+2][l+1][a+r], DP[i][l][a+r]);
                chmax(DP[i+1][l][a+r-1], DP[i][l][a+r] + V[r]);
                chmax(DP[i+2][l][a+r-1], DP[i][l][a+r]);
            }
        }
    }

    ll ans = 0;
    REP(l,N+1){
        REPi(r,l,N+1){
            chmax(ans, DP[K][l][r]);
        }
    }

    cout << ans << endl;
    return 0;
}
