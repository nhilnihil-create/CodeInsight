#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    long long n, m;
    long long ans = 0;
    vector<int> numList;
    cin >> n >> m;

    priority_queue<pair<int, int>> q;
    rep(i, n)
    {
        int a;
        cin >> a;
        q.push(make_pair(a, 1));
    }

    rep(i, m)
    {
        int b, c;
        cin >> b >> c;
        q.push(make_pair(c, b));
    }

    rep(i, n)
    {
        auto p = q.top();
        q.pop();
        ans += p.first;
        if (p.second > 1)
        {
            p.second--;
            q.push(p);
        }
    }
    cout << ans << endl;
}