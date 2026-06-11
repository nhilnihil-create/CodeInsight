#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 1e5 + 5;
ll n, m, sum;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    deque<ll>dq(n);
    vector<pll>v(m);
    for(int i = 0;i < n;++i)
        cin >> dq[i], sum += dq[i];
    for(int i = 0;i < m;++i)
        cin >> v[i].S >> v[i].F;
    sort(dq.begin(), dq.end());
    sort(v.rbegin(), v.rend());
    for(auto &it : v)
    {
        while(dq.size() && dq[0] < it.F && it.S)
        {
//            cout << dq[0] << ' ' << it.F << '\n';
            sum -= dq[0];
            dq.pop_front();
            sum += it.F;
            it.S--;
        }
    }
    cout << sum;
    return 0;
}
