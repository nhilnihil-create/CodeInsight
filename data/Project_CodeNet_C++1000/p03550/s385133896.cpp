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

    ll N, Z, W;
    cin >> N >> Z >> W;
    vector<ll> a(N);
    Rep (i, N) cin >> a[i];

    ll ans;
    if (N == 1) ans = abs(a[0] - W);
    else ans = max(abs(a[N-1] - W), abs(a[N-1] - a[N-2]));

    cout << ans << endl;
}