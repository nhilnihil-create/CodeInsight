#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define debug_() cerr << "AAAAA" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;
using P = pair<int, int>;

int n, a, b, c;
vector<int> l;
int ans = 1001001001;

void calc(vector<int> &vec)
{
    int tmp = 0;
    int p = 0;
    int q = 0;
    int r = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0)
        {
            p += l[i];
        }
        else if (vec[i] == 1)
        {
            q += l[i];
        }
        else if (vec[i] == 2)
        {
            r += l[i];
        }
    }
    // cout << "------------------" << endl;
    // debug_vec(vec);
    for (int i = 0; i < 3; i++)
    {
        int x = count(vec.begin(), vec.end(), i);
        if (x == 0)
        {
            tmp = 1001001001;
        }
        else
        {
            tmp += (x - 1) * 10;
        }
    }
    // debug(tmp);
    tmp += abs(p - a) + abs(q - b) + abs(r - c);
    if (ans > tmp)
    {
        // debug_vec(vec);
        ans = min(ans, tmp);
    }
    // ans = min(ans, tmp);
}

void dfs(int depth, vector<int> &v)
{
    if (depth == n)
    {
        calc(v);
        // debug_vec(v);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        v[depth] = i;
        dfs(depth + 1, v);
    }
}

int main()
{
    cin >> n >> a >> b >> c;
    l.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    // debug_();
    vector<int> vec(n);

    dfs(0, vec);

    cout << ans << endl;
    return 0;
}