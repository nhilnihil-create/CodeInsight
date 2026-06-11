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
int a[MX], b[MX], c[MX];
signed main(){
    int n,ch;
    cin >> n >>ch;
    rep(i,n) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int total = 200002;
    int tt[total];
    int sum[total];
    rep(i,ch) {
        rep(j,total) tt[j]=0;
        rep(j,n) {
            if(c[j]==i+1) {
                tt[a[j]*2-1]++;
                tt[b[j]*2]--;
                //cout << j+1<<" "<<a[j]<<" "<<b[j] << endl;
            }
        } 
        rep(j,total) tt[j+1]+=tt[j];
        rep(j,total) if(tt[j]>0) sum[j]++;
    }
    int ma=0;
    rep(i,total) ma = max(sum[i],ma);
    cout << ma << endl;
    return 0;
}

