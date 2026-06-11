#include <iostream>
#include <cstring>

using namespace std;

const int N = 8e5;
int n, t, pre[N], last[N], tar[N], q[N], l, r, h[N];
void add(int x, int y)
{
    t++;
    pre[t] = last[x];
    tar[t] = y;
    last[x] = t;
}

void bfs(int st)
{
    l = 1, r = 1;
    q[1] = st;
    memset(h, 0, sizeof(h));
    h[st] = 1;
    while (l <= r)
    {
        int x = q[l++];
        for (int ptr = last[x]; ptr; ptr = pre[ptr])
        {
            int xx = tar[ptr];
            if (!h[xx])
            {
                q[++r] = xx;
                h[xx] = h[x] + 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    bfs(1);
    bfs(q[r]);
    if (h[q[r]] % 3 != 2) cout << "First";
    else cout << "Second"  << endl;
    return 0;
}