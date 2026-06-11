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

int main()
{
    andrew;
    int n;
    cin >> n;
    vector<ll>v(n + 1);
    v[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<ll>mem(100005, 1e9);
    
    mem[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= i + 2; j++)
        {
            if (j < n)
                mem[j] = min(mem[j], mem[i] + abs(v[i] - v[j]));

        }
    }

    cout << mem[n - 1] << endl;

    




}
