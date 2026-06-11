#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;



int main(){
    ll N; cin >> N;
    
    vector<vector<int>> G(N+1, vector<int>(N+1));
    int p = 1, cnt = 0;
    if(N % 2 == 1) p = 0;
        
    for(int i = N; i > N/2+1; i--){
        for(int j = p+1; j < i; j++) {
            G[i][j] = 1;
            G[j][i] = 1;
            cnt++;
            if(p != 0){
                G[p][j] = 1;
                G[j][p] = 1;
                cnt++;
            }
        }
        p++;
    }
    cout << cnt << endl;
    for(int i = 1; i <= N-1; i++){
        for(int j = i+1; j <= N; j++){
            if(G[i][j] == 1) cout << i << " " << j << endl;
        }
    }

}
