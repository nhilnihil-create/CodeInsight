#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;

 
int main(){
    int N; cin >> N;
    vector<vector<ll>> F(N, vector<ll>(10));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++) cin >> F[i][j];
    }

    vector<vector<ll>> P(N, vector<ll>(11));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 11; j++) cin >> P[i][j];
    }

    ll ans = -1e18;
    queue<string> Q;
    Q.push("");
    while(!Q.empty()){
        string S = Q.front(); Q.pop();
        if(S.size() == 10){
            if(S == "0000000000") continue;
            ll Max = 0;
            for(int i = 0; i < N; i++){
                int c = 0;
                for(int j = 0; j < 10; j++) if(F[i][j] ==1 && S[j] == '1') c++;
                Max += P[i][c];
            }
            ans = max(ans, Max);

        }
        else{
            string temp1 = S, temp2 = S;
            temp1+='0';
            temp2 += '1';
            Q.push(temp1); Q.push(temp2);
        }
    }
    cout << ans << endl;

    

}