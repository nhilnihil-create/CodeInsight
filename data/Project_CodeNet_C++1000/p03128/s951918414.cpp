#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

int main(){
    ll match[10] = {0,2,5,5,4,5,6,3,7,6};
    ll n,m; cin >> n >> m;
    vvl v(10);
    vl a(m);
    rep(i,m){
        cin >> a[i];
        v[match[a[i]]].push_back(a[i]);
    }
    sort(a.rbegin(), a.rend());
    rep(i,10) sort(v[i].rbegin(), v[i].rend());
    vl dp(n+1,0);
    rep(i,n){
        if(i != 0 && dp[i]==0) continue;
        rep(j,m){
            ll c = match[a[j]];
            if(i+c<=n){
                if(dp[i+c] <= dp[i]){
                    dp[i+c] = dp[i] + 1;
                }
            }
        }
    }
    ll index = n;
    vl ans;
    while(index != 0){
        rep(i,m){
            if(dp[index] - dp[index-match[a[i]]] == 1){
                if(index-match[a[i]]!=0 && dp[index-match[a[i]]]==0) continue;
                ans.push_back(a[i]);
                index -= match[a[i]];
                break;
            }
        }
    }
    for(auto i : ans) cout << i;
    cout << endl;
}
