#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll H, W, h, w;
    cin >> H >> W >> h >> w;

    put(H*W-h*W-w*H+h*w);
}