#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> V(N+2), T(N+2), accumT(N+2);
    rep(i,1,N+1){
        cin >> T[i];
        T[i] *= 2;
        accumT[i+1] = accumT[i] + T[i];
    }
    rep(i,1,N+1){
        cin >> V[i];
        V[i] *= 2;
    }
    vector<int> p(40010);
    rep(i,0,accumT[N+1]+1){
        rep(j,1,N+2){
            if(accumT[j] >= i){
                p[i] = V[j-1];
                break;
            }
        }
        rep(j,1,N+2){
            int d = abs(accumT[j] - i);
            p[i] = min(p[i], d + min(V[j-1], V[j]));
        }
    }
    int sum = 0;
    rep(i,0,accumT[N+1]+1)sum += p[i];
    printf("%.9lf\n", 0.25 * sum);
}