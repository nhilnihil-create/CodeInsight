#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
#define vt vector
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int MOD = 1e9 + 7;
const int INF = 2e9;
const int N = 1e2 + 5;

int n, ans;
int freq[N];

void solve() {
    int T = 1;
    // cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> n;
        for(int i = 1, x; i <= n; i++) {
            cin >> x;
            freq[x]++;
            if(freq[x] == 1) ans++;
        }
        cout << ans << "\n";
    }
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}