#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int H,W;
    cin >> H >> W;
    int h,w;
    cin >> h >> w;
    cout << H*W-h*W-w*H+h*w << endl;
    return 0;
}