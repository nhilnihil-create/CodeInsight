#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;

ll arr[50];
int main() {
    cin >> N;
    int max_index = -1, max_abs = 0;
    rep(i, N){
        cin >> arr[i];
        if(max_abs < abs(arr[i])){
            max_index = i;
            max_abs = abs(arr[i]);
        }
    }
    if(max_index == -1){
        cout << 0;
        return 0;
    }

    cout << 2*N-2 << endl;
    rep(i, N){
        if(i == max_index) continue;
        cout << max_index+1 << " " << i+1 << endl;
    }
    if(arr[max_index] < 0){
        for(int i=N;i>1;i--){
            cout << i << " " << i-1 << endl;
        }
    }
    else{
        rep(i, N-1){
            cout << i+1 << " " << i+2 << endl;
        }
    }
}
