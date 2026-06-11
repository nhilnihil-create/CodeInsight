#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    int N;
    cin >> N;

    if (N % 2 == 0)
    {
        cout << N;
    }
    else
    {
        N *= 2;
        cout << N;
    }

    return 0;
}
