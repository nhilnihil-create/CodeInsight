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
    ll ans = 0;
    vector<ll> digit;
    while(N > 0)
    {
        digit.push_back(N % 10);
        N /= 10;
    }

    REP(i, digit.size())
    {
        ll d = digit[i];
        if (i + 1 < digit.size())
        {
            if (d != 9)
            {
                digit[i + 1]--;
            }
            ans += 9;
        }
        else
        {
            ans += d;
        }
    }
    cout << ans << endl;
}
