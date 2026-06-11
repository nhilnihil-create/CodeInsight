#include <bits/stdc++.h>

using namespace std;

// Function come here..

int main(int argc, char **argv)
{
    // Problem solution come here...
    int a, b;
    cin >> a >> b;

    int r = a * b;
    r *= a * b;

    if (r % 2 != 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}