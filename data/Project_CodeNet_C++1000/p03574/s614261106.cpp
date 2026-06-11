#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int H, W;
    cin >> H >> W;
    string S = "";
    rep(i, H){
        string temp = "";
        cin >> temp;
        S += temp;
    }
    //cout << S << endl;
    rep(i, H){
        rep(j, W){
            int x = i*W + j;
            if (S[x] == '#'){
                cout << '#' ;
            } else {
                int ans = 0;
                int x_ = x-W-1;
                if ((x_ >= 0) && (x_ >= (i-1)*W) && (x_ < i*W) && (S[x_] == '#')) ans += 1;
                x_ = x-W;
                if ((x_ >= 0) && (x_ >= (i-1)*W) && (x_ < i*W) && (S[x_] == '#')) ans += 1;
                x_ = x-W+1;
                if ((x_ >= 0) && (x_ >= (i-1)*W) && (x_ < i*W) && (S[x_] == '#')) ans += 1;

                x_ = x-1;
                if ((x_ >= 0) && (x_ >= i*W) && (x_ < (i+1)*W) && (S[x_] == '#')) ans += 1;
                x_ = x+1;
                if ((x_ >= 0) && (x_ >= i*W) && (x_ < (i+1)*W) && (S[x_] == '#')) ans += 1;

                x_ = x+W-1;
                if ((x_ < H*W) && (x_ >= (i+1)*W) && (x_ < (i+2)*W) && (S[x_] == '#')) ans += 1;
                x_ = x+W;
                if ((x_ < H*W) && (x_ >= (i+1)*W) && (x_ < (i+2)*W) && (S[x_] == '#')) ans += 1;
                x_ = x+W+1;
                if ((x_ < H*W) && (x_ >= (i+1)*W) && (x_ < (i+2)*W) && (S[x_] == '#')) ans += 1;
                cout << ans;
            }
        }
        cout << endl;
    }
}