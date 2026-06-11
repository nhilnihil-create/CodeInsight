#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n, m;
    cin>>n>>m;
    vector<vector<ll> > v(8, vector<ll>(n));
    rep(i, n){
        vector<ll> use(3);
        rep(i, 3) cin>>use[i];
        for(int bit = 0;bit<(1<<3);bit++){
            vector<int> s(3);
            rep(j, 3){
                if((bit>>j)&1) s[j] = 1;
            }
            ll tmp = 0;
            rep(j, 3){
                if(s[j] == 1){
                    tmp +=use[j];
                }
                else tmp -=use[j];
            }
            v[bit][i] = tmp;
        }
    }
    ll ans = 0;
    rep(i, 8){
        sort(v[i].begin(), v[i].end(), greater<ll>());
        ll tmp = 0;
        rep(j, m) tmp += v[i][j];
        ans=max(ans, tmp);
    }
    cout<<ans<<endl;
    return 0;
}