#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,a,b;
    cin >> n>>a>>b;

    cout << (((b-a) % 2) ? "Borys" : "Alice") << '\n';
    return (0);
}
