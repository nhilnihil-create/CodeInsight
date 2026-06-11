#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define TASK "Yet Another Palindrome Partitioning"

using namespace std;

const int maxn = 2e5 + 1;
string s;
int n,f[(1<<26)],x;

void OpenFile()
{
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
}

void Enter()
{
    cin >> s;
}

void Init()
{

}

void Solve()
{
    fill(f+1,f+(1<<26),s.size());
    for (auto c : s) {
        x ^= 1 << (c - 'a');
        for (int i=0;i<26;++i)
            f[x] = min(f[x],f[x^(1<<i)]+1);
    }
    if (f[x] == 0) f[x] = 1;
    cout << f[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //OpenFile();

    Enter();
    Init();
    Solve();
}
