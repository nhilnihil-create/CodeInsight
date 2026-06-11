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
struct node
{
    ll num, cnt;
};
node a[MAXN * 2];
int tot = 0;
bool cmp(node a, node b)
{
    return a.num > b.num;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a[tot].num = num;
        a[tot++].cnt = 1;
    }
    for(int i = 0; i < m; i++)
    {
        int b, c;
        cin >> b >>c;
        a[tot].num = c;
        a[tot++].cnt = b;
    }
    sort(a, a+ tot, cmp);
    ll ans = 0;
    int i = 0;
    int count = n;
    while(count > a[i].cnt)
    {
        ans += a[i].cnt * a[i].num;
        count -= a[i].cnt;
        i++;
    }
    ans += count * a[i].num;
    cout << ans << endl;
    return 0;
}
