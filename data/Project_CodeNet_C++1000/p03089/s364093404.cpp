#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> b(N);
    REP(i, N)
    {
        cin >> b[i];
    }

    vector<ll> c(N, -1);
    bool flag = true;
    REP(i, N)
    {
        for (ll j = N - 1 - i; j >= 0; --j)
        {
            if (j + 1 == b[j])
            {
                c[N - 1 - i] = j + 1;
                b.erase(b.begin() + j);
                break;
            }
        }
        if (c[N - 1 - i] == -1)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
    }
    else
    {
        REP(i, N)
        {
            cout << c[i] << endl;
        }
    }
}
