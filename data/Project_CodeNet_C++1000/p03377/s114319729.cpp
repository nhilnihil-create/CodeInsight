#include <bits/stdc++.h>

using namespace std;

// Function to solve the problem come here.

int main(int argc, char **argv)
{
    // The solution come here...
    // 1) 3 5 4
    int A, B, X, flag = 0;
    cin >> A >> B >> X;

    for (int i = 0; i <= B; i++)
    {
        if (A + i == X)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}