#include <bits/stdc++.h>
using namespace std;
#define fo(x, n) for(int i = x; i <= n; i++)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector <int> vi;
const int MOD = 1e9 + 7;
void solve(){
    int a, b, t;
    cin >> a >> b >> t;
    int cur = 0, ans = 0;
    while(cur + a <= t){
        cur += a;
        ans += b;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1;
    //cin >> T;
    fo(1, T){
        solve();
    }
}


