#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define _GLIBCXX_DEBUG
#define rep(i, V) for (int i = 0; i < V; i++)
#define repr(i, V) for (int i = V-1; i >= 0; i--)
#define repval(i, a, V) for (int i = a; i < V ; i++)
#define all(x) x.begin(), x.end()
#define ld long double
#define eps 0.0000000001
#define mod 1000000007
#define inf 1e9
#define vec vector
#define each(i, mp) for(auto& i:mp)

int main(){
    int n,k;
    cin >> n >> k;

    vec<int> x(n), y(n);
    vec<int> xary, yary;

    rep(i, n){
        cin >> x[i] >> y[i];
        xary.push_back(x[i]);
        yary.push_back(y[i]);
    }

    sort(all(xary));
    sort(all(yary));

    ll ans = 1LL * (xary[n-1] - xary[0]) * (yary[n-1] - yary[0]);

    rep(xi, n)repval(xj, xi+1, n)rep(yi, n)repval(yj, yi+1, n){
        ll lx = xary[xi], rx = xary[xj];
        ll by = yary[yi], uy = yary[yj];
        int num = 0;
        rep(i, n){
            if(lx <= x[i] && x[i] <= rx && by <= y[i] && y[i] <= uy){
                num++;
            }
        }

        if (num >= k) ans = min(ans, 1LL * (rx-lx) * (uy-by));
    }

    cout << ans << endl;
}