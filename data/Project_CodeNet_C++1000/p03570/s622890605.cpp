#include <bits/stdc++.h>

using namespace std;
#define lint long long
#define P pair<int, int>

const int INF = 1E9;
int mem[(1LL << 26)];

int main(){
    string S;
    cin >> S;
    
    int len = S.length();

    fill(mem, mem + (1LL << 26), INF);
    mem[0] = 0;
    
    lint Cnt[len + 1];
    Cnt[0] = 0;
    for(int i = 1; i < len + 1; ++i){
        Cnt[i] = Cnt[i - 1] ^ (1LL << (S[i - 1] - 'a'));
    }
    
    int dp[len + 1];
    fill(dp, dp + len + 1, INF);
    dp[0] = 0;
    
    for(int i = 1; i < len + 1; ++i){
        for(int j = 0; j < 26; ++j){
            if(mem[Cnt[i] ^ (1LL << j)] < INF){
                dp[i] = min(dp[i], dp[mem[Cnt[i] ^ (1LL << j)]] + 1);
            }
        }
        if(mem[Cnt[i] ^ 0] < INF){
            dp[i] = min(dp[i], dp[mem[Cnt[i] ^ 0]] + 1);
        }
        
        if(mem[Cnt[i]] == INF || dp[mem[Cnt[i]]] > dp[i]){
            mem[Cnt[i]] = i;
        }
        
        
//        cout << dp[i] << " ";
    }
    
    cout << dp[len] << endl;
}