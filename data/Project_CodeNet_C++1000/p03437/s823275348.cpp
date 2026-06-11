#include <iostream>
#include <cstdio>
using namespace std;
char c;
long long  a, b;
long long ans;
bool check()
{
    return a%b==0;
}
void solve()
{
    if (check())
        ans = -1;
    else
        ans = a*(b-1);
    return;
}
main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> a >> b;
    solve();
    cout << ans << endl;
    return 0;
}