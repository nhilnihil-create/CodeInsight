#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

// #define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
using P = pair<int, int>;
using ll = long long;
vector<int> to[100005];
int cost[100005];

ll calc(long a) {
    a++;
    ll ans = 0;
    rep(i, 50) {
        ll loop = (1LL << (i+1)); //2 4 8...
        ll cnt = (a/loop)*(loop/2); //回数*(loopの中の1)
        cnt += max(0LL, a%loop-loop/2); 
        if(cnt%2==1) ans += 1LL<<i;
    }
    return ans;
}

signed main(){
    long long a, b;
    cin >> a >> b;
    ll ans = calc(b)^calc(a-1);
    cout << ans << endl;

    return 0;
}

