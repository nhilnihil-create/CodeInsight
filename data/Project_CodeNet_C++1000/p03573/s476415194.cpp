#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

char lowCaseAlpha[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    fast();

    //freopen("out.txt", "w", stdout);

    ll a, b ,c;
    cin >> a >> b >> c;
    if (a == b) cout << c;
    else if (a == c) cout << b;
    else if (b == c) cout << a;

    return 0;
}