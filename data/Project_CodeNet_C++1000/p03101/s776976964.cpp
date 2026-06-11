#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, begin, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    int ans = H * W - h * W - (H - h) * w;
    cout << ans << endl;
}