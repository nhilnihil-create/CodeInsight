#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> num ={2,5,5,4,5,6,3,7,6};
vector<bool> use(9,false);
const ll INF = ll(1e18)+5;

ll dp[int(1e4)+5];

ll dfs(ll N){
    if(N<0){
        return -INF;
    }
    if(N==0){
        // cerr <<"0" << endl;
        return 0;
    }
    if(dp[N] != -1){
        return dp[N];
    }
    ll retVal =-INF;
    for(int i=0;i<9;i++){
        if(!use[i]){
            continue;
        }
        retVal = max(retVal,dfs((N-num[i]))+1);
    }
    // cerr <<"N=" << N << "dp=" << retVal <<  endl;
    return dp[N] = retVal;
}

int main() {
    
    ll N,M;
    cin >> N>>M;
    for(int i=0;i<N+5;i++){
        dp[i] = -1;
    }
    for(int i=0;i<M;i++){
        int a;
        cin >> a;
        --a;
        use[a] = true;
    }
    ll deg = dfs(N);
    string ans ="";
    while(N>0){
        // cerr <<"N=" << N  <<"deg=" << deg<< endl;
        for(int i=8;i>=0;--i){
            if(!use[i]){
                continue;
            }
            if(dfs(N-num[i]) == deg-1){
                // cerr <<"dp[]=" << dp[N-num[i]]  <<"num[i]=" << num[i]<< endl;
                ans += char('1'+i);
                deg--;
                N -= num[i];
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}