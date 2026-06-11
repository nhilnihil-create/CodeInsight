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
    vector<ll> A(N), B(N);
    REP(i, N)
    {
        cin >> A[i];
        B[i] = A[i] - (i + 1);
    }
    sort(ALL(B));

    ll ans = 0;
    if (N % 2 == 0)
    {
        REP(i, N)
        {
            if (i < N / 2)
            {
                ans += -B[i];
            }
            else
            {
                ans += B[i];
            }
        }
    }
    else
    {
        REP(i, N)
        {
            if (i == N / 2)
            {
                continue;
            }
            else if (i < N / 2)
            {
                ans += -B[i];
            }
            else
            {
                ans += B[i];
            }
        }
    }

    cout << ans << endl;
}
