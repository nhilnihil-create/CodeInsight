#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 2;
    else {
        if (n % 2 == 0)
            cout << n;
        else
            cout << (long long)n*2; 
    }
    cout << endl;

    return 0;
}