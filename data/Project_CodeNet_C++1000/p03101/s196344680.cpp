#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int W,H,w,h;
    cin >> W >> H >> w >> h;
    cout << (W-w)*(H-h) << endl;
    return 0;
}