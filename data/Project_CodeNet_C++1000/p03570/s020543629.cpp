#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.size();
    vector<int> X(N+1,0);
    for(int i=1;i<=N;i++){
        X[i] = X[i-1]^(1<<((S[i-1]-'a')));
    }
    map<int,int> memo;
    vector<int> dp(N+1,1e9);
    memo[0] = 0;
    dp[0] = 0;
    for(int i=1;i<=N;i++){
        int val = X[i];
        if(memo.count(val)){
            dp[i] = memo[val]+1;
        }
        for(int j=0;j<26;j++){
            int key = (1<<j);
            int pre = val^key;
            if(memo.count(pre)){
                dp[i] = min(dp[i],memo[pre]+1);
            }
        }
        if(!memo.count(val)) memo[val] = dp[i];
        else memo[val] = min(memo[val],dp[i]);
    }
    cout << dp[N] << endl;
}