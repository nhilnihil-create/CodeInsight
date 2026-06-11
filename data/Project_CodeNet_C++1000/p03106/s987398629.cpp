#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

int num_divisors(const int n)
{
    int counter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            counter++;
        }
    }
    //cout << n << " " << counter << endl;

    return counter;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, K;
    cin >> A >> B >> K;

    int smaller = (A >= B) ? B : A;

    int counter = 0;
    int answer = 9;
    for (int i = smaller; i >= 1; --i)
    {
        if (A % i == 0 && B % i == 0)
        {
            ++counter;
            if (counter == K)
            {
                answer = i;
            }
        }
    }

    cout << answer << endl;
    return 0;
}