#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cost[1<<16];
ll dp[1<<16];

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
 
    int n;
    cin>>n;
    ll a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                for(int k=j+1;k<n;k++){
                    if(i&(1<<k)) cost[i] += a[j][k];
                }
            }
        }
    }
    for(int bit=0;bit<(1<<n);bit++){
        vector<int> v;
        for(int i=0;i<n;i++){
            if(bit&(1<<i)) v.push_back(i);
        }
        int m = v.size();
        for(int b=0;b<(1<<m);b++){
            int s = 0;
            for(int j=0;j<m;j++){
                if(b&(1<<j)) s += (1<<v[j]);
            }
            dp[bit] = max(dp[bit],dp[bit^s]+cost[s]);
            //cerr << s << " "<<cost[s] << endl;
        }
    }
    cout << dp[(1<<n)-1] << endl;
}