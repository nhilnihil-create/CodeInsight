#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int N, M;
    cin >> N >> M;
    v<int> k(M, 0), p(M);
    vv<int> s(M);

    for (int i = 0; i < M; i++)
    {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++)
        {
            int r;
            cin >> r;
            s[i].push_back(r);
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> p[i];
    }

    int cnt = 0;
    for (int bit = 0; bit < (1 << N); bit++)
    {
        v<bool> v(N, false);
        for (int i = 0; i < N; i++)
        {
            if (bit & (1 << i))
                v[i] = true;
        }

        int right = 0;

        for (int i = 0; i < M; i++)
        {
            int n_s = 0;
            for (int j = 0; j < k[i]; j++)
            {
                if (v[s[i][j]-1])
                    n_s++;
            }
            if (n_s % 2 == p[i])
                right++;
        }

        if (right == M)
            cnt++;
    }

    cout << cnt << endl;
    return 0;
}