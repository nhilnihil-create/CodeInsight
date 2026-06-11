#include <iostream>
#include <cstdio>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
//#include <unordered_map>
using namespace std;
#define dbg(x) cerr << #x " = " << x << endl;
typedef pair<int, int> P;
typedef long long ll;
#define FIN freopen("in.txt", "r", stdin);
const int MAXN = 1e5+5;
int fa[MAXN];
void init()
{
    for(int i = 0; i < MAXN; i++)
    {
        fa[i] = i;
    }
}
int find_root(int x)
{
    return x == fa[x] ? x : fa[x] = find_root(fa[x]);
}
void merge(int x, int y)
{
    int fx = find_root(x), fy = find_root(y);
    if(fx != fy) fa[fy] = fx;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    init();
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        merge(x, y);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(fa[i] == i)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}