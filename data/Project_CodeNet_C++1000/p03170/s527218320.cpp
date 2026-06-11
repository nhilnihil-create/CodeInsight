#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool dp[100005];
ll a[105];

ll f(ll m, ll n){

    for(ll z=1;z<=m;z++){
        for(ll x=0;x<n;x++){
            if(a[x] <= z){
                if(! dp[z - a[x]]) dp[z] = true;
            }
        }
    }

    return dp[m];
}

int main() {

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll n,k;
    cin>>n>>k;

    for(ll x=0;x<n;x++) cin>>a[x];

    memset(dp, false, sizeof dp);

    bool res = f(k, n);

    if(! res) cout<<"Second\n";
    else cout<<"First\n";

    return 0;
}