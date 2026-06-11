#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define int long long

const int N = 5010;
const int MOD = 1e9 + 7;

int n, A, B;
int p[N], pos[N], dp[N];
int ca[N][N], cb[N][N], t[N][N];
int tree[N];

void Add(int pos)
{
    while (pos < N)
    {
        tree[pos]++;
        pos = (pos | (pos - 1)) + 1;
    }
}

int Get(int pos)
{
    int res = 0;
    while (pos > 0)
    {
        res += tree[pos];
        pos = (pos & (pos - 1));
    }
    return res;
}

#define Get(l, r) Get(r) - Get(l - 1)

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
    n++;
    pos[n] = n, p[n] = n;
    for (int j = 0; j <= n; j++)
    {
        fill(tree, tree + N, 0);
        for (int i = j + 1; i <= n; i++)
        {
            ca[j][i] = Get(0, pos[j]);
            cb[j][i] = Get(pos[i], N);
            t[j][i] = (Get(pos[j], pos[i]) == 0);
            Add(pos[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
    	dp[i] = 1e18;
    	for (int j = i - 1; j >= 0; j--)
    	{
    		if (pos[j] < pos[i])
    		{
    		    int CA = ca[j][i], CB = cb[j][i], T = t[j][i];
    			if (T)
    			{
    				dp[i] = min(dp[i], dp[j] + CA * A + CB * B);
    			}
    		}
    	}
    }
    cout << dp[n];
}
