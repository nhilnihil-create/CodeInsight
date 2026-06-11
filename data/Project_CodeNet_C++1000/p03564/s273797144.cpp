#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K, N, O, i;
    cin >> N >> K;
    i = 0;
    O = 1;
    while (i < N)
    {
        i++;
        if (2 * O > O + K)
        {
            O += K;
        }
        else
        {
            O *= 2;
        }
    }
    cout << O << endl;
}