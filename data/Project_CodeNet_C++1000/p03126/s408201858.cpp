#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() 
{
    int n, m;
    cin >> n >> m;
    int V[m];
    rep(i,m) V[i] = 0;
    rep(i,n) {
        int k;
        cin >> k;
        rep(j,k) {
            int a;
            cin >> a;
            a--;
            V[a]++;
        }
    }

    int ans = 0;
    rep(i,m) {
        if (V[i] == n) ans++;
    }

    cout << ans << endl;
    return 0;
}
