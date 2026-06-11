#include <bits/stdc++.h>
using namespace std;

vector<int> u;
vector<int> v;
vector<int> w;

int main()
{
    int L;
    scanf("%d", &L);
    int n = log(L+0.5) / log(2) + 1;
    for (int i = 1; i < n; ++i)
    {
        u.push_back(i);
        v.push_back(i+1);
        w.push_back(1<<(i-1));
        u.push_back(i);
        v.push_back(i+1);
        w.push_back(0);
    }
    int t = 0;
    while (L)
    {
        t ++;
        if (L == 1) break;
        if (L & 1)
        {
            u.push_back(t);
            v.push_back(n);
            w.push_back((L-1) << (t-1));
        }
        L /= 2;
    }
    printf("%d %d\n", n, u.size());
    for (int i = 0; i < u.size(); ++i)
        printf("%d %d %d\n", u[i], v[i], w[i]);
    return 0;
}
