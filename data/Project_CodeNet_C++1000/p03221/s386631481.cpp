#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>

int N;
int M;
vector<pii> mem[100010];
int P[100010];
int num[100010];

signed main()
{
    cin >> N >> M;
    rep(i, M)
    {
        int p, y;
        cin >> p >> y;
        P[i] = p;
        mem[p].push_back({y, i});
    }

    rep(i, N + 1)
    {
        sort(mem[i].begin(), mem[i].end());
        for(int j = 0; j < mem[i].size(); j++)
        {
            pii p = mem[i][j];
            num[p.second] = j + 1;
        }
    }

    rep(i, M)
    {
        vector<char> ans;
        int tmp = 1;
        rep(j, 6)
        {
            ans.push_back((P[i] / tmp) % 10 + '0');
            tmp *= 10;
        }
        reverse(ans.begin(), ans.end());
        for(auto a : ans) cout << a;

        ans.clear();
        tmp = 1;
        rep(j, 6)
        {
            ans.push_back((num[i] / tmp) % 10 + '0');
            tmp *= 10;
        }
        reverse(ans.begin(), ans.end());
        for(auto a : ans) cout << a;
        cout << endl;
    }

    return 0;
}