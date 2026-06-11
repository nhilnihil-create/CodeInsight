#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;


int main(){
    int N, C; cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C)), COL(N, vector<int>(N));
    for(int i = 0; i < C; i++) for(int j = 0; j < C; j++) cin >> D[i][j];
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {cin >> COL[i][j]; COL[i][j]--;}

    vector<vector<ll>> DP(3, vector<ll>(C));

    ll MIN = 1e18;

    for(int i = 0; i < C; i++){ // color
        ll ans1=0, ans2=0, ans3=0;
        for(int h = 0; h < N; h++){
            
            for(int w = 0; w < N; w++){
                int clr = (h+w+2)%3;
                if(clr == 0) ans1 += D[COL[h][w]][i];
                else if(clr == 1) ans2 += D[COL[h][w]][i];
                else ans3 += D[COL[h][w]][i];
            }
        }
        DP[0][i] = ans1;
        DP[1][i] = ans2;
        DP[2][i] = ans3;

    }

    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            for(int k = 0; k < C; k++){
                if(i == j || j == k || k == i) continue;
                MIN = min(MIN, (ll)(DP[0][i] + DP[1][j] + DP[2][k]));
                //cout << 
            }
        }
    }
    cout << MIN << endl;



}