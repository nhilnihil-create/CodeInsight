#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, M, C;
    cin >> N >> M >> C;

    vector<int> B(M);
    rep(i, M) cin >> B.at(i);

    vector<vector<int>> A(N, vector<int>(M));
    rep(i, N) rep(j, M) cin >> A.at(i).at(j);

    int ans = 0;

    rep(i, N)
    {
        int tmp = C;
        rep(j, M)
        {
            tmp += A.at(i).at(j) * B.at(j);
        }

        if (tmp > 0)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}