#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
int a[MAXN];
int b[MAXN];

int solve(int cutoff, int n, int k, int q)
{
    priority_queue<int, vector<int>, greater<int>> mins;
    int ptr = 0;
    while (ptr < n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        while (ptr < n && a[ptr] > cutoff)
        {
            pq.push(a[ptr]);
            ptr++;
        }
        while (pq.size() >= k)
        {
            mins.push(pq.top());
            pq.pop();
        }
        ptr++;
    }
    if (mins.size() < q)
        return 1E9 + 5;
    int small = mins.top();
    for (int i = 0; i < q - 1; i++)
        mins.pop();
    return mins.top() - small;
}

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    int ans = solve(0, n, k, q);
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, solve(a[i], n, k, q));
    }
    cout << ans << endl;
    return 0;
}
