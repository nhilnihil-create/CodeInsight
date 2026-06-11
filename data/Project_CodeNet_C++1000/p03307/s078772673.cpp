#include <bits/stdc++.h>

using namespace std;

// Function to solve the problem come here.

int foo(int N)
{

    int j = N;
    while (true)
    {
        if (j % N == 0 && j % 2 == 0)
            return j;

        j += N;
    }
}

int main(int argc, char **argv)
{
    // Solve the problem here
    int N;
    cin >> N;
    cout << foo(N) << endl;
    return 0;
}