#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int C[200005];
vector<int> colour[200005];

int cnt = 0;
ii rep[200005];

long long dp[200005];

const int MOD = 1e9+7;


int main(){
    // Shin Takarajima
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i ++){
        scanf("%d", &C[i]);
    }

    for(int i = 0; i < N; i ++){
        colour[C[i]].push_back(i);
    }

    for(int i = 1; i < 200001; i ++){
        for(int j = 1; j < (int)colour[i].size(); j ++){
            if(colour[i][j] - colour[i][j-1] > 1){
                rep[cnt++] = ii(colour[i][j], colour[i][j-1]);
            }
        }
    }
    sort(rep, rep+cnt);

    dp[0] = 1;
    int j = 0;
    for(int i = 1; i < N; i ++){
        dp[i] = dp[i-1];
        while(rep[j].first == i){
            dp[i] += dp[rep[j].second];
            j ++;
        }
        dp[i] %= MOD;
    }

    printf("%lld", dp[N-1]);

    return 0;
}
