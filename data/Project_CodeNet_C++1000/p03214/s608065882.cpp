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

    ll N;
    cin >> N;
    vector<ll> a(N);
    ll total = 0;
    Rep (i, N) {
        cin >> a[i];
        total += a[i];
    }

    ll ans = 0;
    Rep (i, N) {
        if (abs(a[i]*N - total) < abs(a[ans]*N - total)) ans = i;
    }

    cout << ans << endl;
}