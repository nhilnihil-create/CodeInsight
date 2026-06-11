#include <iostream>

using namespace std;

const int INF = 10e+7;

int hash_[200001];
int hash_min[1<<26];
int dp[200001];

int main(){
    string s;
    cin >> s;
    int N = s.size();
    int cur = 0;
    for(int i = 0; i < (1<<26); i++){
        hash_min[i] = INF;
    }
    hash_[0] = 0;
    for(int i = 0; i < N; i++){
        cur ^= (1<<(s[i]-'a'));
        hash_[i+1] = cur;
        dp[i+1] = INF;
    }
    
    dp[0] = 0;
    hash_min[0] = 0;
    for(int i = 0; i <= N; i++){
        int h = hash_[i];
        dp[i] = min(INF, hash_min[h]+1);
        for(int j = 0; j < 26; j++){
            int n = (1<<j);
            h = (hash_[i]^n);
            dp[i] = min(hash_min[h]+1, dp[i]);
            hash_min[hash_[i]] = min(hash_min[hash_[i]], dp[i]);
        }
    }
    cout << dp[N] << endl;
}