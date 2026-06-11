#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int H, W, h, w;
    cin >> H >> W >> h >> w;
    cout << H*W - h*W - H*w + h*w << endl;

    return 0;
}