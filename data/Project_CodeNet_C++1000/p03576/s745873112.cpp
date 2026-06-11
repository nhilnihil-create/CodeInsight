#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    vector<int> xary, yary;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        xary.push_back(x[i]);
        yary.push_back(y[i]);
    }
    sort(xary.begin(), xary.end());
    sort(yary.begin(), yary.end());
    ll ans = 1LL * (xary[n-1] - xary[0]) * (yary[n-1] - yary[0]);
    for(int xi = 0; xi < n; xi++){
        for(int xj = xi+1; xj < n; xj++){
            for(int yi = 0; yi < n; yi++){
                for(int yj = yi+1; yj < n; yj++){
                    int lx = xary[xi];
                    int rx = xary[xj];
                    int ly = yary[yi];
                    int ry = yary[yj];
                    int cnt = 0;
                    for(int i = 0; i < n; i++){
                        if(lx <= x[i] && x[i] <= rx
                            && ly <= y[i] && y[i] <= ry){
                            cnt++;
                        }
                    }
                    if(cnt >= k)
                        ans = min(ans, 1LL * (rx - lx) * (ry - ly));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}