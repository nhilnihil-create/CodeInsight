#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N;
char sir[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s", sir + 1), N = strlen (sir + 1);
long long ans = 0;
int cntA = 0;
for (int i=1; i<=N; i++)
    if (sir[i] == 'A') cntA ++;
    else
    if (sir[i] == 'B' && sir[i + 1] == 'C')
        ans += cntA, i ++;
    else
        cntA = 0;
printf ("%lld\n", ans);
return 0;
}
