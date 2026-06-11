#include <bits/stdc++.h>
#define rep(i, N) for (int i = 0; i < N; i++)
#define vec vector<int>
using namespace std;
int main()
{
    int w;
    string S, sum;
    cin >> S >> w;

    rep(i, S.size())
    {
        if (i % w == 0)
        {
            sum += S[i];
        }
    }

    cout << sum << endl;
}
