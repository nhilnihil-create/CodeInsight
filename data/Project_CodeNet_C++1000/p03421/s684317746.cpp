#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    if(a + b > n + 1 || n > a * b)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    ll s = n - a;
    int cur = n;
    for(int i = 1; i <= a; i++)
    {
        ll num = min(s, b-1) + 1;
        s -= num-1;
        for(int j = 1; j <= num; j++)
        {
            ans.push_back(cur-num+j);
        }
        cur -= num;
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
