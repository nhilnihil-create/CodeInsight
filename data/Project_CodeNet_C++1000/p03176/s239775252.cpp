#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iterator>
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
#include <cctype>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)
const int tree_size = (1 << 19);
int n;
vector<int>a, p;
vector<int> mx(tree_size, -2e18);

int get_max(int v, int l, int r, int L, int R) { // l , r - границы L,R запрос
    // если не перес
    // полуинтервал
    if(R <= l || L >= r)
        return -2e18;
    if(L <= l && r <= R)
        return mx[v];
    int m = (r + l)/2;
    return max(
                get_max(2*v+1, l, m, L, R),
                get_max(2*v+2, m, r, L, R)
              );
}

void relax(int v, int l, int r, int i, int x) {
    mx[v] = max(mx[v], x);
    if (r-l==1)
        return;
    int m = (l + r)/2;
    if(i < m)
        relax(2*v+1, l , m, i , x);
    else
        relax(2 * v + 2, m, r, i, x);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    p.resize(n);
    forn(i, n)
        cin >> a[i];
    forn(i, n)
        cin >> p[i];
    vector<int>b=a;
    sort(b.begin(),b.end());
    map<int,int>m;
    forn(i, n)
        m[b[i]]=i;
    forn(i, n)
        a[i]=m[a[i]];
    int ans = 0;
    forn(i, n)
    {
        int cur = max(get_max(0, 0, n, 0, a[i]), 0ll) + p[i];
        ans = max(ans, cur);
        relax(0, 0, n, a[i], cur);
    }
    cout << ans << endl;
    return 0;
}
