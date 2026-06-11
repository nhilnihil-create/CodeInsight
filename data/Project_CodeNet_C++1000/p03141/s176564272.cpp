#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define data pair<int,pii>

int N;
vector<data> V;

signed main()
{
    cin >> N;
    rep(i, N)
    {
        int a, b;
        cin >> a >> b;
        V.push_back({a + b, {a, b}});
    }

    sort(V.rbegin(), V.rend());

    int ans = 0;
    rep(i, N)
    {
        if(i & 1)ans -= V[i].second.second;
        else ans += V[i].second.first;
    }

    cout << ans << endl;

    return 0;
}
