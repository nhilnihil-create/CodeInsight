#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    ll N, M; cin >> N >> M;
    if (N == 1 && M == 1) cout << 1 << endl;
    else if (N == 1) cout << M - 2 << endl;
    else if (M == 1) cout << N - 2 << endl;
    else if (N == 2 || M == 2) cout << 0 << endl;
    else cout << N * M - (ll)(max(N, M) - 2) * (ll)2 - (ll)min(N, M) * (ll)2 << endl;
    return 0;
}