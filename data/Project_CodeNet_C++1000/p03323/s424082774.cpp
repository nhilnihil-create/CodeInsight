#include <bits/stdc++.h>

int main(void)
{
    using namespace std;
    
    int a, b;
    cin >> a >> b;
    int cuts = 16;
    cout << ((a > cuts / 2 || b > cuts / 2) ? ":(" : "Yay!") << endl;
}