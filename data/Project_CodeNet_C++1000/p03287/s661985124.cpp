#include <iostream>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <complex>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>

#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const int N = 1e5 + 5, inf = 1e9, mod = 1e9 + 7;

using namespace std;

int main()
{
    IO
    int n, m, a;
    ll sum = 0, ans = 0;
    map<int, int>mp;
    cin >> n >> m;
    mp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        sum = (sum + a) % m;
        ans += mp[sum];
        mp[sum]++;
    }
    cout << ans << '\n';
    return 0;
}