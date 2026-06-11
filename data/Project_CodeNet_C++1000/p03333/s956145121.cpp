#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n;
pair<int, int> p[100002];

bool viz[100002];
ll tryy(int md)
{
    memset(viz, 0, sizeof(viz));
    set<pair<int, int> >sL, sR;
    for(int i = 1; i <= n; ++i)
    {
        sL.insert({p[i].fi, i});
        sR.insert({p[i].se, i});
    }
    ll ans = 0;
    int pos = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i % 2 == md)
        {
            pair<int, int> current;
            current = *sL.rbegin();
            sL.erase(current);
            int tg = current.se;
            if (pos <= p[tg].se)
            {
                ans += max(p[tg].fi - pos, 0);
                if (pos < p[tg].fi)
                    pos = p[tg].fi;
            }
            else
            {
                ans += max(pos - p[tg].se, 0);
                pos = p[tg].se;
            }
            sR.erase(sR.find({p[tg].se, tg}));
        }
        else
        {
            pair<int, int> current;
            current = *sR.begin();
            sR.erase(current);
            int tg = current.se;
            if (pos >= p[tg].fi)
            {
                ans += max(pos - p[tg].se, 0);
                if (pos > p[tg].se)
                    pos = p[tg].se;
            }
            else
            {
                ans += max(p[tg].fi - pos, 0);
                pos = p[tg].fi;
            }
            sL.erase(sL.find({p[tg].fi, tg}));
        }
    }
    return ans + abs(pos);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> p[i].fi >> p[i].se;
    cout << max(tryy(1), tryy(0)) << '\n';
    return 0;
}
