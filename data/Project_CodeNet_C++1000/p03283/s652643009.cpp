#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N,M,Q;
    cin >> N >> M >> Q;
    ll A[N][N];
    ll B[N][N];
    rep(i,N){
        rep(j,N){
            A[i][j] = 0;
            B[i][j] = 0;
        }
    }
    rep(i,M){
        ll L,R;
        cin >> L >> R;
        A[L-1][R-1]++;
    }
    rep(i,N){
        rep(j,N){
            if(j==0) B[i][j] = A[i][j];
            else B[i][j] = B[i][j-1]+A[i][j];
        }
    }
    rep(i,Q){
        ll p,q;
        cin >> p >> q;
        ll out = 0;
        for(ll j=p-1;j<q;j++){
            if(p==1) out += B[j][q-1];
            else out += B[j][q-1]-B[j][p-2];
        }
        cout << out << endl;
    }
    return 0;
}
