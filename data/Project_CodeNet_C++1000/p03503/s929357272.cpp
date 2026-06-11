#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
vector<vector<int>>v;
vector<int> ans;
void solve(int idx, int one)
{
    if(idx >= 10)
    {
        if(one)
            v.push_back(ans);
        return;
    }

    ans.push_back(1);
    solve(idx + 1, one + 1);
    ans.pop_back();

    ans.push_back(0);
    solve(idx + 1, one);
    ans.pop_back();

    return;
}
int main()
{
    Hello
    solve(0, 0);
    int n;
    ll ans = -1e10;
    cin >> n;
    int arr[n + 5][15], shop[n + 5][15];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 10; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 11; j++)
            cin >> shop[i][j];
    for(int i = 0; i < v.size(); i++)
    {
        ll cur = 0;
        for(int k = 0; k < n; k++)
        {
            int common = 0;
            for(int j = 0; j < 10; j++)
                if(arr[k][j] == v[i][j] && arr[k][j])
                    common++;
            cur += shop[k][common];
        }
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}
