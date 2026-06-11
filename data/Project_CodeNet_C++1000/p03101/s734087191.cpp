#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int H , W , h , w;

int main()
{
    _FastIO;
    cin >> H >> W;
    cin >> h >> w;
    int x = H - h;
    int y = w * x;
    int ans = y + h * W;
    cout << (H * W) - ans << endl;
    return 0;
}
