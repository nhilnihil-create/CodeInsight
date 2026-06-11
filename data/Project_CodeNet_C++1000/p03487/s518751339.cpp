#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    map<int, int> B;

    for (int i = 0; i < N; i++)
    {
        B[A.at(i)]++;
    }

    int ans = 0;
    int b = 0;
    for (int i = 0; i < N; i++)
    {
        b = B[A.at(i)];
        if (b > 0 && b != A.at(i))
        {
            if (b > A.at(i))
            {
                ans += b - A.at(i);
            }
            else
            {
                ans += b;
            }
            B[A.at(i)] = 0;
        }
    }

    cout << ans << endl;
    return 0;
}