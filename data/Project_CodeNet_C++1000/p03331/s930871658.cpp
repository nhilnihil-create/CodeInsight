#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int N;
    cin >> N;
    int minsum = 1e9;
    for (int i = 1; i < N; i++)
    {
        int j = N - i;
        int ii = i, jj = j;
        int ti = 0, tj = 0;
        rep(k, 6)
        {
            ti += ii % 10;
            tj += jj % 10;
            ii /= 10;
            jj /= 10;
        }
        int sum = ti + tj;
        minsum = min(minsum, sum);
    }
    cout << minsum << endl;
    return 0;
}