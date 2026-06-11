#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
//#define int long long

signed main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    
    int x_max = x, y_min = y;
    rep(i,n){
        int t; cin >> t;
        x_max = max(x_max, t);
    }
    rep(i,m){
        int t; cin >> t;
        y_min = min(y_min, t);
    }
    
    if(x_max < y_min) cout << "No ";
    cout << "War" << endl;
}