#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> x(N),y(N),h(N);
    int candx, candy, candh;
    for (int i=0;i<N;i++) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i]>0) {
            candx = x[i];
            candy = y[i];
            candh = h[i];
        }
    }
    bool end = false;
    int ansx, ansy;ll ansh;
    for (int xx=0;xx<=100;xx++){
        for (int yy=0;yy<=100;yy++){
            ll H = candh + abs(candx - xx) + abs(candy - yy);
            for (int i=0;i<N;i++){
                ll hh = H - abs(x[i] - xx) - abs(y[i]-yy);
                if (max(hh,0LL) != h[i]) break;
                if (i==N-1){
                    ansx = xx;
                    ansy = yy;
                    ansh = H;
                    end = true;
                    break;
                }
            }
            if (end) break;
        }
        if (end) break;
    }
    cout << ansx << " " << ansy << " " << ansh << "\n";
}