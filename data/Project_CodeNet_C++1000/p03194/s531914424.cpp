#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()

{
    /*long long int n, p;

    cin >> n >> p;
    int ans = 1;
    if (n == 1)
    {
        cout << p;
        return 0;
    }
    for (int i = 2; i <= p; i++)
    {

        if (p % i == 0)
        {
            long long int p1 = p;

            int a = 0;

            while (p1 % i == 0)
            {

                p1 /= i;
                a += 1;
            }
            if (a >= n)
            {

                p = p1;
                for (int j = 0; j < a / n; j++)
                {
                    ans *= i;
                }
            }
        }
    }

    cout << ans;
    */
    long long int N, P;
    cin >> N >> P;
    if (N == 1)
    {
        cout << P << endl;
        return 0;
    }
    else
    {
        long long int ans = 1;
        for (int i = 2; i <= 1000000; i++)
        {
            long long int A;
            A = pow(i, N);
            if (P % A == 0)
            {
                ans = i;
            }
        }
        cout << ans << endl;
        return 0;
    }
}
