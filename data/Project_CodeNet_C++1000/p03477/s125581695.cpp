#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

char lowCaseAlpha[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    fast();

    //freopen("out.txt", "w", stdout);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll left = a + b;
    ll right = c + d;
    if (left > right)
        cout << "Left";
    else if (right > left)
        cout << "Right";
    else 
        cout << "Balanced";
    return 0;
}