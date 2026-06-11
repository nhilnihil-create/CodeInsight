#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    ll N, M;
    cin >> N >> M;

    vector<vector<ll>> box(N, vector<ll>(2));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> box[i][j];
        }
    }
    sort(box.begin(), box.end());

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += min(M, box[i][1]) * box[i][0];
        M -= min(M, box[i][1]);
        if (M == 0)
        {
            break;
        }
    }
    cout << ans << endl;
    return (0);
}