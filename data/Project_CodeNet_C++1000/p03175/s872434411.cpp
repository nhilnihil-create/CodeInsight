#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int mod=1e9+7;
    int n;
    cin >> n;
    if (n==1) {
        cout<<2;
        return 0;
    }
    vector<int> d(n+1);
    vector<pair<int,int>> dp(n+1);
    vector<vector<int>> adj(n+1);
    for (int i=1;i<=n-1;++i){
        int a,b;
        cin >> a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        d[a]++;d[b]++;
    }
    queue<int> q;
    for (int i=1;i<=n;++i) if (d[i]==1) q.push(i);
    int last=0;
    while (!q.empty()){
        int a=q.front();q.pop();
        last=a;
        long black=1,white=1;
        for (int& b:adj[a]){
            if (d[b]==0){
                black=(black*dp[b].first)%mod;
                white=(white*((long)dp[b].first+dp[b].second))%mod;
            } else if (d[b]>1){
                d[b]--;
                if (d[b]==1) q.push(b);
            }
        }
        d[a]=0;
        dp[a]={white,black};
    }
    int ans=(dp[last].first+dp[last].second)%mod;
    cout << ans;
}