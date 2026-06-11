#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fl first
#define fr second
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;

const int N = 200000 + 5;

char s[N];

int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1), ans = n;
    for (int i = 2; i <= n; i++)
        if (s[i] != s[i - 1]) ans = min(ans, max(i - 1, n - i + 1));
    printf("%d\n", ans);
    return 0;
}