#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 998244353;
using ll = long long;
using P = pair<ll, ll>;
double PI = acos(-1);
int L,R;
int a[502][502];
signed main(){
    int n,m,q;
    cin >> n >> m >>q;
    int total = 502;
    rep(i,m) {
        cin >> L >> R;
        a[L][R]++;
//        cout << L<<R<<" "<<a[L][R]<<endl;
    }
    FOR(i,1,n+1) FOR(j,1,n+1) a[i][j] += a[i-1][j];
    FOR(i,1,n+1) FOR(j,1,n+1) a[i][j] += a[i][j-1];

    // rep(i,n+1) {
    //     rep(j,n+1) {
    //         cout << a[i][j] << flush;
    //     }
    //     cout << "" << endl;
    // }
    
    rep(i,q) {
        int x,y;
        cin >>x>>y;
        //cout << a[y][y]<<a[x-1][y]<<a[y][x-1]<<a[x-1][x-1] << endl;
        int ans = a[y][y]-a[x-1][y]-a[y][x-1]+a[x-1][x-1];
        cout << ans << endl;
    }

    return 0;
}

