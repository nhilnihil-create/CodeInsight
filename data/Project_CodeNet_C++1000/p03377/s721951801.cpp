#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e9;

int main()
{
    int a, b, x;
    cin >> a >> b >> x;
    if(b >= x - a && x >= a)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
