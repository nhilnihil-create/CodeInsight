#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef array<ll,2> pll;
const ll NMAX=100005,MOD=1e9+7;
bool dp[NMAX];
ll v[NMAX];
int main()
{
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++) cin>>v[i];
    for(ll i=1;i<=k;i++){
        for(ll j=0;j<n;j++){
            if(i-v[j]>=0 && dp[i-v[j]]==0){
                dp[i]=1;
                break;
            }
        }
    }
    cout<<(dp[k]?"First":"Second");
    return 0;
}

///ABCDEFGHIJKLMNOPQRSTUVWXYZ
///11110111100000000000000000
