#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    ll N, M;
    cin >> N >> M;
    ll C = 1900 * M + 100 * (N - M);
    ll ans = C * pow(2LL, M);
    cout << ans << endl;
}
