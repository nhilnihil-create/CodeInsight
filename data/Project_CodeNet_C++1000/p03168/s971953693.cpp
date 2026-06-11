

/* Don't try to copy it!
                    nhi too,
                         goli maar ke cheed bana dunga...;););)
 
                 
    _/﹋\_
    (҂`_´)
    <,︻╦╤─҉- - - - - - - - => - => - =>
    _/﹋\_
                
*/
 
#include "bits/stdc++.h"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define pb push_back
#define f(a) for(ll i = 0;i<a;i++)
#define rep(i,a,b) for(ll i = a;i<b;i++)
#define rrep(i,a,b) for(ll i = a;i>b;i--)
#define vll vector<ll>
#define T ll t; cin>>t; while(t--)
#define freeopen freopen("input.txt","r",stdin);
#define freeclose freopen("output.txt","w",stdout);
#define MOD 1000000007
using namespace std;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }


double dp[3002][3002],P[3002];
ll vis[3002][3002],N;

double solve(ll pos,ll heads){
    
    if(heads < 0) return 0.0;

    if(pos == 0){
        return (heads == 0);
    }

    if(vis[pos][heads]) return dp[pos][heads];
    vis[pos][heads] = 1;

    return dp[pos][heads] =  (P[pos])*solve(pos-1,heads-1) + (1.0 - P[pos])*solve(pos-1,heads);

}

main(){

    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> P[i];
    }

    double tot = 0;
    for(ll heads = 0;heads<=N;heads++){
        ll tails = N - heads;
        if(heads > tails) tot += solve(N,heads);
    }

    printf("%.9lf\n",tot);

    
}