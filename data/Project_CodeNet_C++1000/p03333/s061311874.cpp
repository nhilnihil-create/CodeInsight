#include<bits/stdc++.h>

using namespace std;

int N, l[100009], r[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &l[i], &r[i]);
sort (l, l + N + 1);
sort (r, r + N + 1);
long long ans = 0, curr = 0;
for (int i=1; i<=N; i++)
    curr += l[N - i + 1] - r[i - 1],
    ans = max (ans, curr);
printf ("%lld\n", 2LL * ans);

return 0;
}
