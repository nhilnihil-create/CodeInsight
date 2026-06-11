#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    int x = e - a;
    if (x > k) {
        cout << ":(" << endl;
    } else {
        cout << "Yay!" << endl;
    };

    return 0;
}