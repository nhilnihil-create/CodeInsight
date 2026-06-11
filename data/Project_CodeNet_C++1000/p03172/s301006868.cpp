#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

const int mod = 1000000007;
vector<int> a(100005), dp(100005, 0), dp2(100005, 0), &od = dp, &nw = dp2;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    od[0] = 1;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 0; j <= k; j++)
        {
            sum += od[j];
            sum %= mod;
            if(j-a[i]-1 >= 0)
                sum -= od[j-a[i]-1], sum += mod, sum %= mod;
            nw[j] = sum;
        }
        swap(od, nw);
    }
    cout << od[k] << endl;
}