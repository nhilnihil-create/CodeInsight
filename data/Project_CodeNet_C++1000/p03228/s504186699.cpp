#include <bits/stdc++.h>
#define rep(i, N) for (int i = 0; i < N; i++)
using namespace std;
int main()
{
    int A, B, N, i = 0;
    cin >> A >> B >> N;
    while (1)
    {
        A /= 2;
        B += A;
        i++;
        if (i == N)
        {
            break;
        }
        B /= 2;
        A += B;
        i++;
        if (i == N)
        {
            break;
        }
    }
    cout << A << " " << B << endl;
}
