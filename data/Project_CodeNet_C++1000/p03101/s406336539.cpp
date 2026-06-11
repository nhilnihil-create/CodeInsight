#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    cout << (H - h) * (W - w) << '\n';
    return 0;
}
