#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxN = 1000010;
int n, m;
int Q[100];
char s[maxN];

ll cal(int k)
{
    ll res = 0;
    ll numD = 0, numM = 0, numC = 0;
    ll work = 0;
    int l = 0, r = k - 1;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'D')
        {
            numD++;
        }
        if (s[i] == 'M')
        {
            work += numD;
            numM++;
        }
        if (s[i] == 'C')
        {
            res += work;
            numC++;
        }
    }
    while (r < n - 1)
    {
        if (s[l] == 'D')
        {
            numD--;
            work -= numM;
        }
        if (s[l] == 'M')
        {
            numM--;
        }
        if (s[l] == 'C')
        {
            numC--;
        }
        l++;
        r++;
        if (s[r] == 'D')
        {
            numD++;
        }
        if (s[r] == 'M')
        {
            work += numD;
            numM++;
        }
        if (s[r] == 'C')
        {
            numC++;
            res += work;
        }
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &Q[i]);
    for (int i = 0; i < m; i++)
        printf("%lld\n", cal(Q[i]));
    return 0;
}

