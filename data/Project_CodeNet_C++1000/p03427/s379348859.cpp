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
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
    int n;
    cin >> n;
    int keta = log10(n)+1;
    int c = n;
    int ma = 0;
    while(c>0) {
        ma+=(c%10);
        c/=10;
    }
    cout << max(ma,(keta-1)*9+(int)(n/pow(10,keta-1))-1) << endl;
}

