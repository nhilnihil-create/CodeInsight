#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define eps 1e-12

int t[105], v[105];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
        t[i] += t[i - 1];
    }
    for(int i = 0; i < n; i++)
        cin >> v[i];
    ld cur = 0;
    ld sol = 0;
    for(int i = 0; i < n; i++)
    {
        ld st = t[i], en = t[i + 1], ans;
        for(int j = 0; j < 70; j++)
        {
            ld mid = (st + en) / 2;
            ld curSpeed = min((ld)v[i], cur + (mid - t[i]));
            bool good = 1;
            for(int k = i + 1; k <= n; k++)
                if(!(curSpeed - (t[k] - mid) <= v[k]))
                    good = 0;
            if(good)
                ans = mid, st = mid;
            else
                en = mid;
        }
        st = t[i], en = ans;
        ld acc, cons, desc = t[i + 1] - ans, ss;
        for(int j = 0; j < 100; j++)
        {
            ld mid = (st + en) / 2;
            ld curSpeed = cur + mid - t[i];
            if(curSpeed <= v[i])
                acc = mid - t[i], cons = ans - mid, ss = curSpeed, st = mid;
            else
                en = mid;
        }
        sol += cur * acc + 0.5 * acc * acc;
        sol += ss * cons;
        sol += ss * (t[i + 1] - ans) + 0.5 * -1 * (t[i + 1] - ans) * (t[i + 1] - ans);
        cur = ss + -1 * (t[i + 1] - ans);
    }
    cout << fixed << setprecision(6) << sol;
}
