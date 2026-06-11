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

int n, m;
vector<int> graph[500000];
string s;

int cntA[500000], cntB[500000];
int marked[500000];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u, v--, u--;
        graph[v].push_back(u);
        graph[u].push_back(v);
        if (s[v] == 'A') cntA[u]++; else cntB[u]++;
        if (s[u] == 'A') cntA[v]++; else cntB[v]++;
    }
    vector<int> q;
    for (int i = 0; i < n; i++) if (!cntA[i] || !cntB[i]) q.push_back(i), marked[i] = 1;
    for (int i = 0; i < q.size(); i++)
    {
        if (s[q[i]] == 'A') for (auto v : graph[q[i]]) {cntA[v]--; if (!marked[v] && !cntA[v]) q.push_back(v), marked[v] = 1;}
        if (s[q[i]] == 'B') for (auto v : graph[q[i]]) {cntB[v]--; if (!marked[v] && !cntB[v]) q.push_back(v), marked[v] = 1;}
    }
    if (q.size() == n)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
}
