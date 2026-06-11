#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    char b;
    cin >> b;

    if (b == 'A')
        puts("T");
    if (b == 'T')
        puts("A");
    if (b == 'C')
        puts("G");
    if (b == 'G')
        puts("C");
}