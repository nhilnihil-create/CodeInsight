#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<vector<int> > f(n, vector<int>(10));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            cin >> f[i][j];
        }
    }
    vector<vector<ll> > p(n, vector<ll>(11));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 11; j++){
            cin >> p[i][j];
        }
    }

    ll ans = -(1 << 30);
    for(int bit = 1; bit < (1 << 10); bit++){
        int cc = 0;
        for(int i = 0; i < n; i++){
            int c = 0;
            for(int j = 0; j < 10; j++){
                if(bit & (1 << j) && f[i][j]) c++;
            }
            cc += p[i][c];
        }
        if(ans < cc) ans = cc;
    }
    cout << ans << endl;
}
