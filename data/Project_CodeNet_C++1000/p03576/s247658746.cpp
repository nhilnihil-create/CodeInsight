#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int n,k;
    cin >> n >>k;
    vector<int> x(n),y(n);
    vector<int> xx, yy;
    rep(i, n)
    {
        cin >> x[i] >> y[i];
        xx.push_back(x[i]);
        yy.push_back(y[i]);
    }
    sort(xx.begin(),xx.end());
    sort(yy.begin(), yy.end());
    ll ans = 1LL * (xx[n - 1] - xx[0]) * (yy[n - 1] - yy[0]);
    rep(xi,n){
        for (int xj = xi + 1; xj < n; xj++){
            rep(yi,n){
                for (int yj = yi + 1; yj < n;yj++){
                    int num = 0;
                    ll lx = xx[xi],rx = xx[xj];
                    ll ly = yy[yi],ry = yy[yj];
                    for (int i = 0; i < n;i++){
                        if(lx <= x[i] && x[i] <= rx && ly <= y[i] && y[i] <= ry){
                            num++;
                        }
                    }

                    if(num >= k)
                        ans = min(ans, 1LL * (rx - lx) * (ry - ly));
                }
            }
        }
    }
    cout << ans << endl;
}