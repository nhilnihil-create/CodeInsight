#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = int(1e9);
typedef long long int ll;
/* -- template -- */

int main(){
    int X, Y, Z, K; cin >> X >> Y >> Z >> K;
    ll A[X], B[Y], C[Z];
    rep(i, X)cin >> A[i];rep(i, Y)cin >> B[i];rep(i, Z)cin >> C[i];
    sort(A, A + X, greater<ll>());sort(B, B + Y, greater<ll>());sort(C, C + Z, greater<ll>());
    ll sumAB[X * Y];
    int count = 0;
    rep(i, X){
        rep(j, Y){
            sumAB[count] = A[i] + B[j];
            ++count;
        }
    }
    count = 0;
    sort(sumAB, sumAB + X*Y, greater<ll>());
    ll sumABC[K * Z];
    for(int i = 0;i < ((K < X * Y) ? K : X * Y);++i){
        for(int j = 0;j < Z;++j){
            sumABC[count] = sumAB[i] + C[j];
            ++count;
        }
    }
    sort(sumABC, sumABC + ((K < X * Y) ? K : X * Y) * Z, greater<ll>());
    rep(i, K)cout << sumABC[i] << endl;
}
