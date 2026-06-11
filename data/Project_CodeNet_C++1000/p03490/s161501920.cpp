#include<bits/stdc++.h>
using namespace std;
char s[10005];
int p[2], n;
vector < int > d[2];
bitset < 30000 > inq;
bool check(int k) 
{
    queue < int > q, q2; q.push(0); inq.reset();
    for (int i = 0; i < d[k].size(); ++i, swap(q, q2))
        for (int u, v; !q.empty();)
		{
            u = q.front(); q.pop(); inq[u+10000] = 0;
            v = u + d[k][i];
            if (!inq[v+10000]) q2.push(v), inq[v+10000] = 1;
            v = u - d[k][i];
            if (!inq[v+10000]) q2.push(v), inq[v+10000] = 1;
        }
    for (; !q.empty(); q.pop())
        if (q.front() == p[k]) return true;
    return false;
}
int main() {
    scanf("%s", s);
    scanf("%d%d", &p[0], &p[1]);
    n = strlen(s);
    for (int fir = 1, m = 0, i = 0, t = 0; i < n; ++i) 
	{
        if (s[i] == 'F') ++m;
        if (s[i] == 'T' || i == n - 1) 
		{
            if (fir) p[0] -= m, m = fir = 0;
            if (m) d[t].push_back(m);
            m = 0, t ^= 1;
        }
    } puts(check(0) && check(1) ? "Yes" : "No");
    return 0;
}