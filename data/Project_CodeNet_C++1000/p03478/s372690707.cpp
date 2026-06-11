#include <iostream>
#include <math.h>
using namespace std;

int sumOfDigits(int n)
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
    int N, A, B;
    cin >> N >> A >> B;
    int answer = 0;
    for (int i = 1; i < N + 1; ++i)
    {
        int compare = sumOfDigits(i);
        if (compare >= A && compare <= B)
        {
            answer += i;
        }
        compare = 0;
    }
    cout << answer << endl;
}