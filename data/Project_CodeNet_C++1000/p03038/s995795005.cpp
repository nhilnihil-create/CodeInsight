#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<int, int>> g;
    rep(i,M) {
        int a,b;
        cin >> a >> b;
        g.emplace_back(b, a);
    }
    sort(g.begin(),g.end(), greater<pair<int,int>>());
    int i = 0;
    for (auto m : g) {
        for (int j = 0; j < m.second; j++) {
            if (a[i] >= m.first)
                break;
            a[i] = m.first;
            i++;
        }
    }
    ll ans = 0;
    rep(i, N) ans += a[i];
    cout << ans << endl;
}