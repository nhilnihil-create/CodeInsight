#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, H, W;
    cin >> N >> H >> W;
    ll ans = 0;
    Rep (i, N) {
        ll a, b;
        cin >> a >> b;
        if (a >= H && b >= W) {
            ans++;
            // cout << i << "\n";
        }
    }

    cout << ans << "\n";
}