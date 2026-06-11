#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, c;
    int b = 30;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        c = 0;
        cin >> A;
        while (A % 2 == 0)
        {
            A = A / 2;
            c++;
        }
        if (c < b)
        {
            b = c;
        }
    }
    cout << b << endl;
}
