#include <bits/stdc++.h>
#include <vector> 
#include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;

int arr[100][100];
signed main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[n];
    rep(i,n) cin >> a[i];
    b[0]=a[0];
    FOR(i,1,n) {
        b[i] = b[i-1] + a[i];
    } 
    map<int, int> mp;

    rep(i,n) {
        mp[b[i]%m]++;
    }
    mp[0]++;
    int ans = 0;
    for(auto e: mp) {
        ans += e.second*(e.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}
