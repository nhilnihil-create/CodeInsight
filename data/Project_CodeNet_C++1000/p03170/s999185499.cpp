#include<bits/stdc++.h>
using namespace std;


int N, K;
vector<int> A(110);
vector<bool> dp(100010, false);

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int k = 0; k <= K; k++){
        for(int i = 0; i < N; i++){
            if(k+A[i] > K) continue;
            dp[k+A[i]] = (!(dp[k]) || dp[k+A[i]]);
        }
    }

    if(dp[K]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
