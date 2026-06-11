#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> A(H);
    REP(i, H)
    {
        cin >> A[i];
    }

    queue<pair<ll, ll>> q;
    REP(i, H)
    {
        REP(j, W)
        {
            if (A[i][j] == '#')
            {
                pair<ll, ll> p = make_pair(i, j);
                q.push(p);
            }
        }
    }

    ll ans = 0;
    while(true)
    {
        queue<pair<ll, ll>> nextQ;
        while(!q.empty())
        {
            pair<ll, ll> p = q.front();
            q.pop();
            ll i, j;
            i = p.first;
            j = p.second;
            if (j - 1 >= 0 && A[i][j - 1] == '.')
            {
                A[i][j - 1] = '#';
                nextQ.push(make_pair(i, j - 1));
            }
            if (j + 1 < W && A[i][j + 1] == '.')
            {
                A[i][j + 1] = '#';
                nextQ.push(make_pair(i, j + 1));
            }
            if (i - 1 >= 0 && A[i - 1][j] == '.')
            {
                A[i - 1][j] = '#';
                nextQ.push(make_pair(i - 1, j));
            }
            if (i + 1 < H && A[i + 1][j] == '.')
            {
                A[i + 1][j] = '#';
                nextQ.push(make_pair(i + 1, j));
            }
        }
        if (!nextQ.empty())
        {
            ans++;
            q = nextQ;
        }
        else
        {
            break;
        }
    }

    cout << ans << endl;
}
