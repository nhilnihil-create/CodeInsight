#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int H, W;
    cin >> H >> W;

    int h, w;
    cin >> h >> w;

    cout << (H - h) * (W - w) << endl;
    
    return 0;
}
