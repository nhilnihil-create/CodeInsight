#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> v, dp;
ll c, n, MOD=1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;
    v=vector<ll>(n);
    dp=vector<ll>(c+1, 0);
    dp[0]=1;
    for(ll i=0; i<n; i++){
        cin >> v[i];
        vector<ll> pre(c+1, 0);
        for(ll used=c; used>=0; used--){
            if(used+1<used+min(v[i], c-used)+1){
                pre[used+1]+=dp[used];
                if(used+min(v[i], c-used)+1<=c)
                    pre[used+min(v[i], c-used)+1]-=dp[used];
            }
        }
        ll sum=0;
        for(ll j=0; j<=c; j++){
            sum=(sum+pre[j]+MOD)%MOD;
            dp[j]=(dp[j]+sum)%MOD;
        }
    }
    cout << dp[c] << endl;
	return 0;
}
