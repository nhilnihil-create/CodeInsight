#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;


int main(){
    ll H, W; cin >> H >> W; 
    vector<vector<ll>> A(H, vector<ll>(W)), C(10, vector<ll>(10));
    for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) cin >> C[i][j];

    map<ll, ll> M;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
            if(A[i][j] != -1) M[A[i][j]]++;
        }
    }
    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < 10; i++){
        ans += M[i] * C[i][1];
    }
    cout << ans << endl;



    

    
}
