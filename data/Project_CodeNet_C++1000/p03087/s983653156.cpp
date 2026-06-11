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
    string t; cin>>t;

    ll s[n+1]; s[0]=0;
    rep(i,n){
        if(t.substr(i,2)=="AC") s[i+1]=s[i]+1;
        else s[i+1]=s[i];
    }
    rep(i,q){
        int l,r; cin>>l>>r;
        l--; r--;
        cout<<s[r]-s[l]<<endl;
    }
    return 0;
}