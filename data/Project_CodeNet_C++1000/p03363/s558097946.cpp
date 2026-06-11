#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
map<ll, int> mp;
int main() {
    int n;
    cin >> n;
    ll sum = 0;
    mp[0]++;
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        sum += a;
        ret += mp[sum];
        mp[sum]++;
    }
    cout << ret << endl;
    return 0;
}