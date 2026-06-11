#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N)
    {
        cin >> A[i];
    }
    vector<ll> B(M), C(M);
    vector<pair<ll, ll>> swapP;
    REP(i, M)
    {
        cin >> B[i] >> C[i];
        swapP.push_back(make_pair(C[i], B[i]));
    }

    sort(ALL(A));
    sort(ALL(swapP));
    reverse(ALL(swapP));

    ll index = 0;
    bool flag = true;
    REP(i, M)
    {
        pair<ll, ll> p = swapP[i];
        ll b, c;
        b = p.second;
        c = p.first;
        REP(j, b)
        {
            if (A[index] < c)
            {
                A[index] = c;
                index++;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    ll ans = 0;
    REP(i, N)
    {
        ans += A[i];
    }

    cout << ans << endl;
}
