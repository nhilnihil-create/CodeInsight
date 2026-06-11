#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define F first
#define S second
#define pb push_back
#define PI 3.14159265
#define sz(c) (int)c.size()
#define len(c) (int)c.length()
#define hcf(a, b) __gcd(a, b)
#define all(c) c.begin(), c.end()
#define vint vector<int>
#define vll vector<ll>
#define vpint vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define tr(container, it) \
    for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define fr(it, a, b) \
    for (int it = (a); it < (b); it++)
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container), element) != container.end())
#define maximum(a, b, c) (a > b ? (a > c ? a : c) : (b > c ? b : c))
#define minimum(a, b, c) (a < b ? (a < c ? a : c) : (b < c ? b : c))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long lu;
const ll mod = 1e9 + 7;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, ans = 0, sum = 0;
    cin >> n >> m;
    vll a(n);
    map<ll, ll> M;
    fr(i, 0, n)
    {
        cin >> a[i];
    }
    fr(i, 0, n)
    {
        sum = (sum + a[i]) % m;
        if (sum == 0)
        {
            ans++;
        }
        ans += M[sum];
        M[sum]++;
    }
    cout << ans << "\n";
    return 0;
}