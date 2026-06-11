#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>

int N, M;
int A[100010], B[100010];
vector<pii> V;

signed main()
{
    cin >> N >> M;
    rep(i, N)
    {
        cin >> A[i];
        V.push_back({A[i], 1});
    }
    rep(i, M)
    {
        int b, c;
        cin >> b >> c;
        V.push_back({c, b});
    }

    sort(V.rbegin(), V.rend());

    int ans = 0;
    for(auto ele : V)
    {
        if(ele.second <= N)
        {
            ans += ele.second * ele.first;
            N -= ele.second;
        }
        else
        {
            ans += N * ele.first;
            N = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
