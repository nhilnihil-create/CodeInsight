#include <bits/stdc++.h>
using namespace std;

int findSumOfDigits(int n)
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

    int x;
    x = findSumOfDigits(N);
    cout << (x == 1 ? 10 : x) << endl;
}
