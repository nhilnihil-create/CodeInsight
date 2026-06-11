/*Huyyt*/
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int dir[8][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}, {1, 1}, {1, -1}, { -1, -1}, { -1, 1}};
const int mod = 998244353, gakki = 5 + 2 + 1 + 19880611 + 1e9;
const int MAXN = 2e5 + 5, MAXM = 2e5 + 5, N = 1e5 + 5;
int to[MAXM << 1], nxt[MAXM << 1], Head[MAXN], tot = 1;
inline void addedge(int u, int v)
{
        to[++tot] = v;
        nxt[tot] = Head[u];
        Head[u] = tot;
}
vector<int> l, r;
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n;
        cin >> n;
        l.push_back(0), r.push_back(0);
        for (int i = 1; i <= n; i++)
        {
                int L, R;
                cin >> L >> R;
                l.push_back(L);
                r.push_back(R);
        }
        ll anser = 0;
        sort(l.rbegin(), l.rend());
        sort(r.begin(), r.end());
        for (int i = 0; i <= n; i++)
        {
                if (l[i] > r[i])
                {
                        anser += 2LL * (l[i] - r[i]);
                }
        }
        cout << anser << endl;
        return 0;
}
