#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = int(1e9);
typedef long long int ll;
/* -- template -- */

int main(){
    int N, K; cin >> N >> K;
    string S;cin >> S;
    int dp[100001];
    dp[0] = 0;
    bool zeroflg = false;
    for(int i = 0; i < N; ++i){
        dp[i] = dp[((i - 1 < 0) ? 0 : i - 1)];
        if(S[i] == '0' && !zeroflg){
            zeroflg = true;
            ++dp[i];
        }
        if(S[i] == '1'){
            zeroflg = false;
        }
    }
    int l = 0, r = 1;
    int maxv = 1;
    while(r < N){
        if(dp[r] - ((l - 1 < 0) ? 0 : dp[l - 1]) + ((S[l] == '0' && l != 0) ? 1 : 0) <= K){
            maxv = max(maxv, r - l + 1);
            ++r;
        }else{
            ++l;
        }
        if(r == l)++r;
    }
    cout << maxv << endl;
}
/*
5
1
00101
*/
