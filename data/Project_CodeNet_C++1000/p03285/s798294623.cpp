#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    for (int i = 0; 4 * i <= N; ++i)
    {
        for (int j = 0; 7 * j <= N; ++j)
        {
            if (4 * i + 7 * j == N)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}