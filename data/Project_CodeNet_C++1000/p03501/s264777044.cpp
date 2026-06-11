#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N, A, B, T;

    cin >> N >> A >> B;
    T = N * A;

    if (T < B)
    {
        cout << T << endl;
    }
    else if (T > B)
    {
        cout << B << endl;
    }
    else
    {
        cout << T << endl;
    }
}