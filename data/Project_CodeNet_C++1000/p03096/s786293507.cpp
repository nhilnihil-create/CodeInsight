#include<bits/stdc++.h>

#define ll long long
#define ull unsigneds long long
#define inf 1e18
#define met(a, x) memset(a,x,sizeof(a))

using namespace std;

const ll mod = 1e9 + 7;
const int N = 2e5 + 10;

int c[N];
ll dp[N];
map<int,int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> c[i];
    ll ans=0;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(mp.count(c[i])&&mp[c[i]]+1<i){
            dp[i]=(dp[i]+dp[mp[c[i]]])%mod;
        }
        mp[c[i]]=i;
    }
    cout<<dp[n]<<endl;
    return 0;
}
/*
2
3 2
1 2
2 3
0 0 0
1 0 1
3 2
1 2
2 3
0 0 0
1 1 1
 */