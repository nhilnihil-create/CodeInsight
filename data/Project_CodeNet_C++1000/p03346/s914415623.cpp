#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#define int long
#define ll long long
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e9;
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

int n;
int a[200010];
int dp[200010];
int ans=0;

void solve(){
    rep(i,n){
        dp[a[i]]=dp[a[i]-1]+1;
        ans=max(ans,dp[a[i]]);
    }
    cout << n-ans << endl;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    cin >> n;
    rep(i,n) cin >> a[i];
    solve();
}