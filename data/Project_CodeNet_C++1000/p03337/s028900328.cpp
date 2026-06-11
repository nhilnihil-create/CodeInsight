#include <bits/stdc++.h>

using namespace std;

// Function to solve the problem come here.

int main(int argc, char **argv)
{
    int A, B;
    cin >> A >> B;

    int sum = A + B;
    int sub = A - B;
    int mul = A * B;

    if (sum > sub && sum > mul)
    {
        cout << sum << endl;
    }
    else if (sub > mul)
    {
        cout << sub << endl;
    }
    else
    {
        cout << mul;
    }

    return 0;
}