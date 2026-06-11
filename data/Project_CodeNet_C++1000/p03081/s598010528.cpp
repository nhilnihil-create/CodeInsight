#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2e5 + 2;
int n, m;
int l[N][26], r[N][26];
char s[N];
int L[26], R[26];
struct node
{
    char c, sig;
}q[N];
bool canmove(int pos)
{
    return pos > 0 && pos <= n;
}
void move(int pos, int v)
{
    for (int i = 0; i < 26; i ++){
        if (L[i] == pos)
            L[i] += v;
        if (R[i] == pos)
            R[i] += v;
    }
}
int check(int pos)
{
    for (int i = 1 ; i <= m; i ++)
        if (s[pos] == q[i].c){
            if (q[i].sig == 'L') pos -= 1;
            else
                pos += 1;
            if (pos == 0)return -1;
            if (pos > n) return 1;
        }
    return 0;
}
int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n ; i++) {
        s[i] -= 'A';
        for (int j = 0; j < 26; j ++)
            l[i][j] = l[i - 1][j];
        l[i][s[i]] = i;
    }
    for (int i = 0; i < 26;  i++)
        r[n + 1][i] = n + 1;
    for (int i = n; i >= 1; i --){
        for (int j = 0; j < 26; j ++)
            r[i][j] = r[i + 1][j];
        r[i][s[i]] = i;
    }
    for (int i = 1; i <= m ; i++)
        scanf(" %c %c", &q[i].c, &q[i].sig), q[i].c -= 'A';
    int L = 1 , R = n, mid, LL = n + 1, sig, RR = 0;
    while (L <= R)
    {
        mid = (L + R) / 2;
        sig = check(mid);
        if (!sig)
            LL = min(LL, mid), R = mid - 1;
        else
            if (sig < 0)
                L = mid + 1;
            else
                R = mid - 1;
    }
    L = 1 , R = n;
    while (L <= R)
    {
        mid = (L + R) / 2;
        sig = check(mid);
        if (!sig)
            RR = max(RR, mid), L = mid + 1;
        else
        if (sig < 0)
            L = mid + 1;
        else
            R = mid - 1;
    }

    printf("%d\n", max(0, RR - LL + 1));
    return 0;
}