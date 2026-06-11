#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int main()
{
    Hello
    int n, m;
    cin >> n >> m;
    int arr[n + 5];
    ll sum[n + 5] = {};
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    map<int, int> mp;
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i];
    for(int i = 0; i <= n; i++)
    {
        ans += mp[sum[i] % m];
        mp[sum[i] % m]++;
    }
    cout << ans;
    return 0;
}
