#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

void solve()
{
    if(fabs(a-c) <= d) printf("Yes\n");
    else {
        if(fabs(a-b) <= d && fabs(b-c) <= d) printf("Yes\n");
        else printf("No\n");
    }
}

int main()
{
    cin >> a >> b >> c >> d;
    solve();
    return 0;
}