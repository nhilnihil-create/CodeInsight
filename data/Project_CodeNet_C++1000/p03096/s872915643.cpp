#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    int N; cin>>N;
    vector<int> left(N,-1);
    vector<int> cleft(200010,-1);
    int c;
    for (int i = 0; i < N; ++i) {
        cin>>c; --c;
        if(cleft[c]>=0){
            left[i]=cleft[c];
        }
        cleft[c]=i;
    }

    vector<ll> dp(N,0ll);
    dp[0]=1;
    for (int i = 1; i < N; ++i) {
        dp[i]=dp[i-1];
        if(left[i]==-1) continue;
        if(i-left[i]>1) (dp[i]+=dp[left[i]])%=MOD;
    }

    cout<<dp[N-1]<<endl;

    return 0;
}
