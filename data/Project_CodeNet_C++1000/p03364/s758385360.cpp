#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool judge(vector<string> V){
    ll N = V.size();
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(V[i][j] != V[j][i]) return false;
        }
    }
    return true;

}

int main(){
    ll N; cin >> N;
    vector<string> V(N); for(int i = 0; i < N; i++) cin >> V[i];
    ll ans = 0;
    for(int A = 0; A < N; A++){
        vector<string> U(N);
        for(int i = 0; i < N; i++){
            U[(i+A)%N] = V[i];
        }
        if(judge(U)) ans+= N;
    }
    cout << ans << endl;
}