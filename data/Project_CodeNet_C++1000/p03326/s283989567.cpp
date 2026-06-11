#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
    int N, M;
    vector<Int> X(1010), Y(1010), Z(1010);
    cin >> N >> M;
    rep(i,N) cin >> X[i] >> Y[i] >> Z[i];

    Int ans = 0; 
    rep(bits, 8){
        bool x = bits&1, y = (bits>>1)&1, z = (bits>>2)&1;

        vector<Int> cakes; 
        rep(i, N){
            Int now = 0;
            if(x) now += X[i]; else now -= X[i];
            if(y) now += Y[i]; else now -= Y[i];
            if(z) now += Z[i]; else now -= Z[i];
            
            cakes.push_back(now);
        }
        sort(cakes.begin(), cakes.end(), greater<Int>());

        Int sum = 0;
        rep(i, M) sum += cakes[i];

        ans = max(ans, sum);
    }

    cout << ans << endl;

}