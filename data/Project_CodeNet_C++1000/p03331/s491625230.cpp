#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int SumOfDegits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;

    int MIN = INT32_MAX;

    for (int i = 1; i < N; i++)
    {
        int a = i;
        int b = N - i;
        int sum = SumOfDegits(a) + SumOfDegits(b);

        if (MIN > sum)
            MIN = sum;
    }

    cout << MIN << endl;

    return 0;
}