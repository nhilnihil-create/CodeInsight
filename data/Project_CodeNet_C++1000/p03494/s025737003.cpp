#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, j, k;
    j = 300;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        if (A % 2 == 0)
        {
            for (k = 0; A % 2 == 0; k++)
            {
                A /= 2;
            }
            if (k < j)
            {
                j = k;
            }
        }
        else
        {
            j = 0;
            break;
        }
    }
    cout << j << endl;
}
