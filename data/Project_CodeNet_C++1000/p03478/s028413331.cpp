#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n)
{
    if (n < 10) return n;

    return n % 10 + digit_sum(n / 10);
}

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int sum = 0;
    int d_sum = 0;
    for (int i = 1; i <= N; i++)
    {
        d_sum = digit_sum(i);
        if (A <= d_sum && d_sum <= B)
        {
            sum += i;
        }
    }
    cout << sum << endl;
}
