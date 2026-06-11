#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
ll num = 0;
ll solve(ll n, ll p)
{
    ll res = 1;
    ll cnt = 0;
    while(p % 2 == 0)
    {
        num++;
        cnt++;
        p /= 2;
    }
    if(cnt >= n) res *= pow(2, cnt / n);
    for(ll i = 3; i * i <= p; i += 2)
    {
        cnt = 0;
        while(p % i == 0)
        {
            num++;
            cnt++;
            p /= i;
        }
        if(cnt >= n) res *= pow(i, cnt / n);
    }
    return res;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, p;
    cin >> n >> p;
    ll ans = solve(n, p);
    if(n == 1) cout << p << endl;
    else if(n > num) cout << 1 << endl;
    else cout << ans << endl;
    return 0;
}

