#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0, temp = n;
    while (temp > 0)
    {
        sum += temp % 10;
        temp /= 10;
    }
    if (n % sum == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}