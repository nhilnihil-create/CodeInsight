#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    int k = min(a, c);
    ans += k;
    a -= k, c -= k;
    k = min(b, c);
    ans += 2 * k;
    b -= k, c -= k;
    ans += b;
    if (c)
        ++ans;
    cout << ans << endl;
}
