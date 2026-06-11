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
    ll r, d, x; cin >> r >> d >> x;
    ll tmp = x;
    for (int i = 1; i <= 10; i++) {
        tmp = r * tmp - d;
        cout << tmp << "\n";
    }
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
