#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;

int main(){
    ll n; cin >> n;
    vl t(n),v(n);
    ll time = 0;
    rep(i,n){
        cin >> t[i];
        time += t[i];
    }
    rep(i,n) cin >> v[i];
    vl tab(40005);
    ll index = 0;
    rep(i,n){
        rep(j,t[i]){
            tab[index] = v[i];
            if(j==t[i]-1) tab[index+1] = min(v[i],v[i+1]);
            else tab[index+1] = v[i];
            index+=2;
        }
    }
    vector<vector<double>> dp(2*(time+1),vector<double>(205,-1));
    dp[0][0] = 0.0;
    //rep(i,60) cout << tab[i] << " ";
    rep(i,2*time){
        rep(j,201){
            if(dp[i][j] != -1){
                if(j+1 <= tab[i]*2) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + j*0.5*0.5 + 0.125);
                if(j <= tab[i]*2) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + j*0.5*0.5);
                if(j >= 1 && j-1 <= tab[i]*2) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] - 0.125 + j*0.5*0.5);
            }
        }
    }
    printf("%.5f\n",dp[2*time][0]);
}