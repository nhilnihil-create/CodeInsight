#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    ll N, M;
    string S, T;
    cin >> N >> M;
    cin >> S;
    cin >> T;

    bool flag = true;
    REP(i, N)
    {
        if ((M * i) % N == 0)
        {
            ll j = (M * i) / N;
            if (S[i] != T[j])
            {
                flag = false;
                break;
            }
        }
    }
    ll ans = flag ? (M * N) / gcd(M, N) : -1;

    cout << ans << endl;
}
