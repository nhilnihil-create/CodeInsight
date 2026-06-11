#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, x; cin >> a >> b >> x;

    if(a > x)
        cout << "NO\n";
    else if((a + b) < x)
        cout << "NO\n";
    else if(a == x)
        cout << "YES\n";
    else if((a + b) >= x)
        cout << "YES\n";
    


    return 0;
}