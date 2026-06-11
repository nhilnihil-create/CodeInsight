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
const int mod = 1e9+7;

signed main(){
    int n, a, b;
    cin >> n >> a >> b;
    int ma = min(a,b);
    int mi = (n - a - b >= 0) ? 0: a+b-n;
    cout << ma<<" "<<mi << endl;
    return 0;
}