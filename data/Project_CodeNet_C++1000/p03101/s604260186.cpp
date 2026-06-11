#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    ll sum = H * W;
    sum -= h * W;
    sum -= w * H;
    sum += h * w;
    cout << sum << endl;
    return 0;
}