#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 100001
ll a[MAXN];
map<ll, ll> mp;
int main() {
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    ll ret = 0;
    mp[0]++;
    for (int i = 1; i <= n; i++) {
        sum = (sum + a[i]) % m;
        ret += mp[sum];
        mp[sum]++;
    }
    cout << ret << endl;
    return 0;
}