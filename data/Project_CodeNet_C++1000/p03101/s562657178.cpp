#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    int all = H * W;
    all -= h * W;
    all -= w * H;
    all += h * w;
    cout << all;
    return 0;
}
