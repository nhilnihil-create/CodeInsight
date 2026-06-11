#include <bits/stdc++.h>
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
int n, c;
int channel[32][202020];
int32_t main()
{
	usecppio
    cin >> n >> c;
    for (int i = 0; i<n; i++)
    {
        int s, t, ch;
        cin >> s >> t >> ch;
        channel[ch][s*2-1]++;
        for (int j = s; j<=t; j++)
        {
            channel[ch][j*2]++;
            channel[ch][j*2+1]++;
        }
        channel[ch][t*2+1]--;
    }
    int ans = 0;
    for (int i = 0; i<202020; i++)
    {
        int ct = 0;
        for (int j = 0; j<32; j++)
            ct += (channel[j][i]>0);
        ans = max(ans, ct);
    }
    cout << ans << '\n';
}