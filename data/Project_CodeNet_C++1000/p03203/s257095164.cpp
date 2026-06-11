#include <bits/stdc++.h>

#define MAX_N 200000

using namespace std;

set <int> lin[MAX_N + 1];
set <int> col[MAX_N + 1];

int rez;

int n;
int h, w;

void readFile()
{
    cin >> h >> w >> n;

    int i;
    int a, b;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a >> b;
        lin[a].insert(b);
        col[b].insert(a);
    }

    for(int i = 1; i <= w; i ++)
        col[i].insert(h + 1);
}

void solve()
{
    rez = h + w;

    int l = 1;
    int c = 1;
    int cr = 0;

    while(l <= h && c <= w)
    {
        set <int> :: iterator it = col[c].lower_bound(l);

        rez = min(rez, (*it) - l + cr);

        cr ++;
        l ++;

        if(c < w && col[c + 1].find(l) == col[c + 1].end())
            c ++;
    }
}

void printFile()
{
    cout << rez << "\n";
}

int main()
{
    readFile();

    solve();

    printFile();

    return 0;
}
