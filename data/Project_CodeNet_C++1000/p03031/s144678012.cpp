#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> K(M);
    vector<vector<int>> S(M, vector<int>(N));

    rep(i, M)
    {
        cin >> K.at(i);
        rep(j, K.at(i))
        {
            cin >> S.at(i).at(j);
        }
    }

    vector<int> P(M);

    ll ans = 0;
    rep(i, M) cin >> P.at(i);

    for (int i = 0; i < (1 << N); i++)
    {
        bitset<10> tmp(i);
        bool ok = false;

        for (int j = 0; j < M; j++)
        {
            int cnt = 0;
            for (int k = 0; k < K.at(j); k++)
            {
                if (tmp.test(S.at(j).at(k) - 1))
                {
                    cnt++;
                }
            }

            ok = cnt % 2 == P.at(j);
            if (!ok)
            {
                break;
            }
        }

        if (ok)
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}