#include <iostream>
#include <vector>
using namespace std;

pair<int, int> search(int from, int to, vector<vector<int>> &g)
{
    pair<int, int> result = {0, to};
    for (int next : g[to])
    {
        if (next != from)
        {
            auto tmp = search(to, next, g);
            tmp.first += 1;
            if (result.first < tmp.first)
            {
                result = tmp;
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto tmp = search(-1, 0, g);
    auto cmp = search(-1, tmp.second, g);
    int diameter = cmp.first;

    cout << ((diameter % 3 != 1) ? "First" : "Second") << endl;

    return 0;
}
