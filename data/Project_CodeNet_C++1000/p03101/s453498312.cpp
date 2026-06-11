/*
      author : nishi5451
      created: 11.08.2020 21:27:48
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int H,W,h,w;
    cin >> H >> W >> h >> w;
    int ans = H*W - h*W - w*H + h*w;
    cout << ans << endl;
    return 0;
}