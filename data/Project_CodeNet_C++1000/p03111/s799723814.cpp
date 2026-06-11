#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

void dfs(const ll N, const ll A, const ll B, const ll C, const vector<ll>& l, vector<ll>& v, ll& ans)
{
    ll n = v.size();
    if (n == N)
    {
        ll a = 0, b = 0, c = 0;
        ll countA = 0, countB = 0, countC = 0;
        REP(i, N)
        {
            if (v[i] == 1)
            {
                a += l[i];
                countA++;
            }
            else if (v[i] == 2)
            {
                b += l[i];
                countB++;
            }
            else if (v[i] == 3)
            {
                c += l[i];
                countC++;
            }
        }
        if (a == 0 || b == 0 || c == 0)
        {
            return;
        }
        else
        {
            ll mp = 10 * (countA + countB + countC - 3);
            mp += abs(A - a) + abs(B - b) + abs(C- c);
            ans = min(ans, mp);
            return;
        }
    }
    else
    {
        REP(i, 4)
        {
            v.push_back(i);
            dfs(N, A, B, C, l, v, ans);
            v.pop_back();
        }
    }

    return;
}

int main()
{
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<ll> l(N);
    REP(i, N) 
    {
        cin >> l[i];
    }

    ll ans = LONG_MAX;
    vector<ll> v;
    dfs(N, A, B, C, l, v, ans);

    cout << ans << endl;
}
