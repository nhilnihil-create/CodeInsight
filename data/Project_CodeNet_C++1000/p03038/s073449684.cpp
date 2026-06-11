#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, mod = 1e9 + 7;
int n, m;
int a[N];

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    cin >> n >> m;
    ll ans = 0;
    int last = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    priority_queue<pair<int, int>> v;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        v.push({y, x});
    }
    while (!v.empty() && last < n)
    {
        pair<int, int> cur = v.top();
        v.pop();
        while (last < n && cur.second > 0 && a[last] < cur.first)
            a[last++] = cur.first,
            cur.second--;
    }
    for (int i = 0; i < n; i++)
        ans += a[i];
    cout << ans << endl;
    return 0;
}