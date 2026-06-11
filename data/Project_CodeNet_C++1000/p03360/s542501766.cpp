#include <bits/stdc++.h>

using namespace std;

// Function to solve the problem come here.

int main(int argc, char **argv)
{
    // The solution come here...
    // 1) 3 5 4
    int A, B, C, T;
    cin >> A >> B >> C;
    cin >> T;

    int sum;
    for (int i = 0; i < T; i++)
    {
        if (A > B && A > C)
        {
            A = 2 * A;
        }
        else if (B > C)
            B = 2 * B;
        else
            C = 2 * C;

        sum = A + B + C;
    }

    cout << sum << endl;

    return 0;
}