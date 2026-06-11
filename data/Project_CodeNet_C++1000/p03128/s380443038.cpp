#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<int,int> P;

vector<int> num = {0,2,5,5,4,5,6,3,7,6};

int main(){
    int N, M; vector<int> A(9);

    cin >> N >> M;
    rep(i,M) cin >> A[i];
    sort(A.begin(), A.begin()+M, greater<int>());

    // dp[i]: マッチちょうどi本で作れる最大桁数
    vector<int> dp(10010, -1);
    dp[0] = 0;
    rep(i,N) rep(j,M){
        if(i+num[A[j]] <= N){
            dp[i+num[A[j]]] = max(dp[i+num[A[j]]], dp[i]+1);
        }
    }

    string ans;
    while(N > 0){
        rep(i,M){
            if(N-num[A[i]] >= 0 && dp[N-num[A[i]]] == dp[N]-1){
                ans.push_back(A[i] + '0');
                N -= num[A[i]];
                break;
            }
        }
        //cout << ans << " " << N << endl;
    }

    cout << ans << endl;
}
