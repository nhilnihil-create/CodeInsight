#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    string S;
    cin >> S;
    ll n = S.size();
    vector<ll> countW(n, 0);
    countW[0] = S[0] == 'W' ? 1 : 0;
    REP(i, n - 1)
    {
        countW[i + 1] = countW[i];
        if (S[i + 1] == 'W')
        {
            countW[i + 1]++;
        }
    }
    ll ans = 0;
    REP(i, n)
    {
        if (S[i] == 'B')
        {
            ans += countW[n - 1] - countW[i];
        }
    }

    cout << ans << endl;
}
