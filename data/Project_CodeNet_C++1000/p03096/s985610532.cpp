#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
int N;
vector<int> C;
vector<int> nc[200010];
ll dp[200010] = {1};
int nxt[200010];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        C.push_back(c);
        nxt[i] = N;
    }

    C.erase(unique(C.begin(), C.end()), C.end());

    for(int i = 0; i < (int)C.size(); i++){
        nc[C[i]].push_back(i);
    }

    for(int i = 0; i <= 2e5; i++){
        for(int j = 0; j < (int)nc[i].size() - 1; j++){
            nxt[nc[i][j]] = nc[i][j + 1];
        }
    }

    for(int i = 0; i < C.size(); i++){
        dp[i + 1] += dp[i];
        dp[i + 1] %= mod;
        dp[nxt[i]] += dp[i];
        dp[nxt[i]] %= mod;
    }

    cout << dp[C.size() - 1] << endl;
    return 0;
}