#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;



void solve() {
    int a, b; cin >> a >> b;
    if (a >= 13) cout << b;
    else if (a >= 6) cout << b / 2;
    else cout << 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
