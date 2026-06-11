#include <bits/stdc++.h>
using namespace std;
int main(void){
    int H,W;
    int h,w;
    cin >> H >> W;
    cin >> h >> w;
    int ans = (H-h)*(W-w);
    if(ans >= 0) cout << ans << endl;
    else cout << 0 << endl;
}
