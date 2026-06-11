
// Problem : K - Stones
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_k
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;

#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define endl '\n'
#define vi vector<ll>
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define pb push_back
#define fi first
#define se second
#define vvi vector<vi>
#define all(x) x.begin(), x.end()

const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N = 1e5 + 5;
ll dp[N] = {0};
//dp[i] ->1 if first wins

int main() {
    SPEED;
    ll n, k;
    cin>>n>>k;
    vi v(n);
    for(ll i = 0; i < n; i++) {
    	cin>>v[i];
    }
    for(ll i = 0; i <= k; i++) {
    	for(ll x:v) {
    		if(x <= i && !dp[i - x]) {
    			dp[i] = 1;
    		}
    	}
    }
    if(dp[k])cout<<"First";
    else cout<<"Second";
    return 0;
}