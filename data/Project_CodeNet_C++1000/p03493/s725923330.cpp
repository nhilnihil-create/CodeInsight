#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, count = 0;
    cin >> a;
    while (a > 0) {
        if (a % 10 == 1) count++;
        a = a/10;
    }
    cout << count << endl;
}
