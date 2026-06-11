#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll MOD = 1e9+7;
const static ll INF = 1e14;


int main() {
    ll N; cin >> N;
    string S; cin >> S;
    vector<vector<ll>> DP(N+1, vector<ll>(N+1, 0));
    for(int i = 0; i < N; i++) DP[0][i] = 1;
    vector<ll> D = DP[0];
    if(S[0] == '<') for(int i = D.size()-2; i >= 0; i--) D[i] = D[i]+D[i+1];
    else for(int i = 1; i < N; i++) D[i] = D[i]+D[i-1];

    for(int i = 1; i < N; i++){
        if(S[i-1] == '<'){
            for(int j = 0; i+j < N; j++){
                DP[i][j] = D[j+1]%MOD;
            }
        }
        else {
            for(int j = 0; i+j < N; j++){
                DP[i][j] = D[j]%MOD;
            }
        }
        if(i == N-1) break;
        D = DP[i];
            if(S[i] == '<') for(int i = D.size()-2; i >= 0; i--) D[i] = (D[i]+D[i+1])%MOD;
            else for(int i = 1; i < N; i++) D[i] = (D[i]+D[i-1])%MOD;
    }
    cout << DP[N-1][0]%MOD << endl;


}
