#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    vector<int> c(N);
    rep(i, N) cin >> c[i];
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x = v[i] - c[i];
        if (x > 0)
            ans += x;
    }
    cout << ans << endl;
}