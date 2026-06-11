#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()

const long long INF = 1e14;

int n;
int x[5000], y[5000];
vector<int> ans;
vector<char> s[5000];

int r(int x, int y)
{
    return abs(x) % y;
}

char U = 'U', D = 'D', L = 'L', R = 'R';
set<int> c;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
    {
        c.insert(r(x[i] + y[i], 2));
    }
    if (c.size() > 1)
    {
        cout << -1, exit(0);
    }
    int gg = *c.begin();
    if (gg == 0)
    {
        for (int i = 0; i < n; i++)
            s[i].push_back(U), y[i]--;
        ans.push_back(1);
    }
    long long ss = 0;
    for (int i = 0; i < 31; i++)
    {
        ss += (1LL << i);
        ans.push_back(1LL << i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        swap(x[i], y[i]);
        int nx = x[i] + y[i];
        int ny = x[i] - y[i];
        x[i] = nx, y[i] = ny;
        long long kekex = ss - nx, kekey = ss - ny;
        kekex /= 2;
        kekey /= 2;
        for (int j = 0; j < 31; j++)
        {
            int x = ((1 << j) & kekex) > 0;
            int y = ((1 << j) & kekey) > 0;
            if (!x && !y) s[i].push_back(U);
            if (!x && y) s[i].push_back(R);
            if (x && y) s[i].push_back(D);
            if (x && !y) s[i].push_back(L);
        }
        for (auto e : s[i]) cout << e;
        cout << "\n";
    }
}
