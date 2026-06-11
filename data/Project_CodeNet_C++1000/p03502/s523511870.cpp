#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n);

int main()
{
    int N;
    cin >> N;
    if (N % digit_sum(N) == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
int digit_sum(int n)
{
    if (n < 10)
        return n;
    return digit_sum(n / 10) + n % 10;
}