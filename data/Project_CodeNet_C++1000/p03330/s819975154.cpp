#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF =ll(1e18) +1;

int main() {
    int N,C;
    cin >> N >>C;
    vector<vector<int>> D(C);
    for(int i=0;i<C;i++){
        for(int j=0;j<C;j++){
            int d;
            cin >> d;
            D[i].push_back(d);
        }
    }
    vector<vector<int>> Color(N);

    vector<pair<int,int>> A,B,E;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int x;
            cin >> x;
            --x;
            Color[i].push_back(x);
            if((i+j)%3==0){
                A.emplace_back(i,j);
            }
            if((i+j)%3 ==1){
                B.emplace_back(i,j);
            }
            if((i+j) %3 ==2){
                E.emplace_back(i,j);
            }
        }
    }
    ll dA[C] ={};
    ll dB[C] = {};
    ll dD[C] ={};
    for(int i=0;i<C;i++){

        for(auto p:A){
            int targetC = Color[p.first][p.second];
            dA[i] += D[targetC][i];
        }
        for(auto p:B){
            int targetC = Color[p.first][p.second];
            dB[i] += D[targetC][i];
        }
        for(auto p:E){
            int targetC = Color[p.first][p.second];
            dD[i] += D[targetC][i];
        }
    }
    ll ans = INF;
    for(int i=0;i<C;i++){
        for(int j=0;j<C;j++){
            if(i ==j){
                continue;
            }
            for(int k =0;k<C;k++){
                
                if(j == k || i ==k){
                    continue;
                }
                
                ans =min(ans,dA[i]+dB[j]+dD[k]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}