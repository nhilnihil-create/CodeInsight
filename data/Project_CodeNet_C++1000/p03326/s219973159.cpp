#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n, m;
    cin>>n>>m;
    vector<vector<ll> > v(8, vector<ll>(n));
    rep(i, n){
        ll a, b, c;
        cin>>a>>b>>c;
        v[0][i] = a+b+c;
        v[1][i] = a+b-c;
        v[2][i] = a-b+c;
        v[3][i] = a-b-c;
        v[4][i] = -a+b+c;
        v[5][i] = -a+b-c;
        v[6][i] = -a-b+c;
        v[7][i] = -a-b-c;
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