#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9
 
// #define fisier 1
 
using namespace std;
 
typedef long long ll;
 
int n, v[200002];
deque<pair<int, int> >d;
bool chk(int mx)
{
    d.clear();
    for(int i = 1; i <= n; ++i)
    {
        if(v[i] > v[i-1])
            d.pb({v[i] - v[i-1], 1});
        else
        {
            int sum = v[i-1];
            while(sum >= v[i])
            {
                pair<int, int> x = d.back();
                if(sum - x.fi >= v[i])
                {
                    sum -= x.fi;
                    d.pop_back();
                }
                else
                {
                    int dif = sum - v[i];
                    x.fi -= dif;
                    d.pop_back();
                    if(x.fi)
                        d.pb(x);
                    sum = v[i];
                    break;
                }
            }
            while(!d.empty())
            {
                pair<int, int> x = d.back();
                if(x.se == mx)
                {
                    sum -= x.fi;
                    d.pop_back();
                }
                else
                {
                    --x.fi;
                    d.pop_back();
                    if(x.fi)
                        d.pb(x);
                    d.pb({1, x.se + 1});
                    if(v[i] - sum)
                        d.pb({v[i] - sum, 1});
                    break;
                }
            }
            if(d.empty())
                return 0;
        }
    }
    return 1;
}
int main()
{
 
   // ifstream cin("a.in");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];
    int st = 1;
    int dr = n;
    int ans = n;
    while(st <= dr)
    {
        int mid = (st + dr) / 2;
        if(chk(mid))
            ans = mid, dr = mid - 1;
        else
            st = mid + 1;
    }
    cout << ans;
    return 0;
}