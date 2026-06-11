#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
int main()
{
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << (H-h) * (W-w) << endl;
    return 0;
}