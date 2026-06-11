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
const int inf = 1e9+5;
const int mod = 1e9+7;
bool isPrime(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
signed main(){
    int q;
    cin >> q;
    vector<int> a(100001);
    FOR(i,3,100001) {
        if(isPrime(i) && isPrime((i+1)/2)) {
            a[i]=a[i-1]+1;
        }else {
            a[i]=a[i-1];
        }
    }

    rep(i,q) {
        int l,r;
        cin >> l >> r;
        cout << a[r]-a[l-1] << endl;
    }

    return 0;

}
