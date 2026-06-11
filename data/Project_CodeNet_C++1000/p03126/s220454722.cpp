#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int x[30];

int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, n) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            a--;
            x[a]++;
        }
    }
    int ans = 0;
    rep(i, m){
        if(x[i] == n) ans++;
    }
    cout << ans << endl;
    return 0;
}