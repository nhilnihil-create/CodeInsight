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

signed main(){
    int n, m;
    cin >>n >>m;
    vector<P> arr(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        arr[i] = make_pair(a, b);
    }

    sort(arr.begin(),arr.end());

    long now = 0;
    long ans = 0;
    rep(i,n) {
        //cout << arr[i].first << endl;
        long next = min(m-now,(long)arr[i].second);
        now += next;
        ans += next*arr[i].first;
    }

    cout <<  ans << endl;

    return 0;
}

