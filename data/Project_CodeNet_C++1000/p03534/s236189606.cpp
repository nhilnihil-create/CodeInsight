#pragma comment(linker, "/STACK:10240000")
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

char s[MAXN];
int num[5];

int main ()
{
    scanf ("%s", &s);
    int len = strlen (s);
    for (int i = 0; i < len; i ++)
    {
        num[s[i] - 'a'] ++;
    }
    int mins = min (min (num[0], num[1]), num[2]);
    num[0] -= mins;
    num[1] -= mins;
    num[2] -= mins;
    int all = num[0] + num[1] + num[2];
    int maxs = max (max (num[0], num[1]), num[2]);
    if ((maxs <= 1) && (all <= 2))
    {
        printf ("YES\n");
    }
    else
    {
        printf ("NO\n");
    }

    return 0;
}