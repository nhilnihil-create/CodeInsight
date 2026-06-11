#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll sum = 0;
    int n, m;
    cin >> n >> m;
    ll res = 0;
    map<ll, int> freq;
    for (int i = 0; i < n; i++) {
        ll in;
        cin >> in;
        in %= m;
        sum += in;
        sum %= m;
        res += freq[sum];
        freq[sum]++;
    }
    res += freq[0];
    cout << res;
    return 0;
}
