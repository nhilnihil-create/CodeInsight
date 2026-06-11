#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i;
    cin >> i;
    cout << (i % 10) + (i / 10 % 10) + (i / 100 % 10) << endl;
    return 0;
}
