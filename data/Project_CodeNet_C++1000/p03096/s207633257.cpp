#include <bits/stdc++.h>
using namespace std;
 
const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
 
int main(){
    int N, C[200000];
    cin >> N;
    for(int i=0; i<N; i++) cin >> C[i];
 
    int left[200001];
    for(int i=0; i<=200000; i++) left[i] = -1;
    static int64_t dp[200001];
    dp[0] = 1;
    for(int i=0; i<N; i++){
        add(dp[i+1], dp[i]);
        int c = C[i];
        if(left[c] >= 0 && left[c] < i-1) add(dp[i+1], dp[left[c]+1]);
        left[c] = i;
    }
    cout << dp[N] << endl;
    return 0;
}