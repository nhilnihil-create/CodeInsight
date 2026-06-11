#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int ansh, ansn, answ;
    bool end = false;
    for (int h=1;h<=3500;h++){
        for (int n=1;n<=3500;n++){
            int p = N*h*n;
            int q = 4*h*n-N*n-N*h;
            if (q <= 0) continue;
            if (p%q==0) {
                ansh = h;
                ansn = n;
                answ = p/q;
                end = true;
                break;    
            }
        }
        if (end) break;
    }
    cout << ansh << " " << ansn << " " << answ << "\n";
}