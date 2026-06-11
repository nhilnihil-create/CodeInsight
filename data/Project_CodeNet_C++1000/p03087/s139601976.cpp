#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll MOD = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n,q; cin>>n>>q;
    string s; cin>>s;

    vector<ll> sum(n+1,0);
    for(int i=1;i<n;i++){
        sum[i+1]=sum[i];
        if(s[i-1]=='A'&&s[i]=='C') sum[i+1]++;
    }
    rep(i,q){
        int l,r; cin>>l>>r;
        cout<<sum[r]-sum[l]<<endl;
    }
    return 0;
}