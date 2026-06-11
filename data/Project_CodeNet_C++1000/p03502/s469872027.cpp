#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n)
{
    int dig, sum = 0;
    while (n)
    {
        dig = n % 10;
        sum += dig;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;

    cout << (n % digit_sum(n) ? "No" : "Yes") << endl;
    return 0;
}