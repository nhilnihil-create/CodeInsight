#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <fstream>
#include <map>
#include <unordered_map>

using namespace std;
typedef int me;
typedef long long ll;
typedef unsigned long long ull;

#define andrew ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define sz(v) (int)(v.size())
#define all(v) v.begin(), v.end()
#define PI 3.1415926535
#define sin(i) (long double)sin(i *PI / 180.0)
#define cos(i) (long double)cos(i * PI/ 180.0)

ll gcd(ll x, ll y) { return (y == 0) ? x : gcd(y, x % y); }
ull lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int dy8[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int dx8[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int id8[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
struct happ
{
    int a, b, c;
};
int n;
vector<happ>v;
ll mem[100005][4];
ll solve(int i, int last)
{
    if (i == n+1)
        return 0;

    ll& ret = mem[i][last];
    
    if (ret != -1)
        return ret;

    if (last != 1)
        ret = max(ret, solve(i + 1, 1) + v[i].a);
    if (last != 2)
        ret = max(ret, solve(i + 1, 2) + v[i].b);
    if (last != 3)
        ret = max(ret, solve(i + 1, 3) + v[i].c);

    return ret;
}
int main()
{
    andrew;
    cin >> n;
    v.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> v[i].a >> v[i].b >> v[i].c;

    for (int i = 0; i < 100005; i++)
        for (int j = 0; j < 4; j++)
            mem[i][j] = -1;

    cout << solve(0, 0) << endl;



}
