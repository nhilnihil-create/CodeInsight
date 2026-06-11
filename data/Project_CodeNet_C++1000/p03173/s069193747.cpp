
// Problem : N - Slimes
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_n?lang=en
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define Ma7moud_7amdy                                                                                                  \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);                                                                                                     \
    cout.tie(NULL)
#define Open_Sesame Open()
#define all(v) ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(arr, x) memset(arr, x, sizeof arr)
#define endl "\n"
#define watch(x) cout << #x << " = " << x << endl;
#define RT(x) return cout << (x), 0;
#define Accepted 0
typedef long long ll;
typedef vector<int> vi;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
void Open()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}
const int mod = ll(1e9 + 7), N = 2000 + 5;
//“Nobody but you have to believe in your dreams to make them a reality.” ― Germany Kent
int n;
ll a[401], mem[403][403];
ll solve(int l = 1, int r = n)
{
    if (l == r)
        return 0;
    if (l + 1 == r)
        return a[r] - a[l - 1];

    ll &ret = mem[l][r];
    if (~ret)
        return ret;
    ret = 1e15;
    for (int i = l; i < r; i++)
    {
        ret = min(ret, solve(l, i) + solve(i + 1, r) + a[r] - a[l - 1]);
    }
    return ret;
}
int main()
{
    Ma7moud_7amdy;
    // Open_Sesame;
    clr(mem, -1);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    cout << solve() << endl;
}
