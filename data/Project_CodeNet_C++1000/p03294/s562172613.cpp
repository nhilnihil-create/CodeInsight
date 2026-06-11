#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int N;
vector<int> a;


void input() {
    cin >> N;
    a = vector<int>(N);
    rep(i, N) cin >> a[i];
}


int main() {
    input();
    int ans = 0;
    rep(i, N) ans += a[i] - 1;
    cout << ans << endl;
}
