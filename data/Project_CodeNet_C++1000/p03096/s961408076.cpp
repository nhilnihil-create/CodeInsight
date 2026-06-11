#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

int main(){
    int N;
    cin >> N;
    vector<int> C(N);
    for(int i=0; i<N; i++) cin >> C[i];
    vector<int> nxt(N, -1), last(200001, -1);
    for(int i=N-1; i>=0; i--){
        nxt[i] = last[C[i]];
        last[C[i]] = i;
    }
    vector<int64_t> dp(N+1);
    dp[0] = 1;
    for(int i=0; i<N; i++){
        add(dp[i+1], dp[i]);
        if(nxt[i] != -1 && nxt[i] != i+1) add(dp[nxt[i]], dp[i]);
    }
    cout << dp[N] << endl;
}
