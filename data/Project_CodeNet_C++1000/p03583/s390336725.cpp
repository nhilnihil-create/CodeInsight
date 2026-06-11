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

    FOR(i,1,3501) {
        FOR(j,1,3501) {
            int k = (n*i*j);
            int k2 = (4*i*j-n*i-n*j);
            if(k2==0) continue;
            if(k%k2==0) {
                k = k/k2;
                if(0<=k && k<=3500) {
                    cout << i <<" "<<j<<" "<<k << endl;
                    return 0;
                }
            }
        }
    }

  return 0;
}

