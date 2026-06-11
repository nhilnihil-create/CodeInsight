#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<vector<lli>> f(n, vector<lli>(10)), p(n, vector<lli>(11));
    rep(i, n){
        rep(j, 10) cin >> f[i][j];
    }
    rep(i, n){
        rep(j, 11) cin >> p[i][j];
    }
    lli ans = -1e18;
    rep(b, 1<<10){
        if(b == 0) continue;
        lli v = 0;
        rep(i, n){
            lli c = 0;
            rep(j, 10){
                if(b>>j&f[i][j]) c++;
            }
            v+=p[i][c];
        }
        ans = max(ans, v);
    }
    cout << ans << endl;

    return 0;
}
