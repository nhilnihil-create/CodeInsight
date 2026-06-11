#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n, m;
    cin >> n >> m;
    int maxL = -1, minR = 100001;
    rep(i, m) {
        int l, r;
        cin >> l >> r;
        maxL = ::max(maxL,l);
        minR = ::min(minR,r);
    }
    int ans = minR-maxL;
    if(ans>=0){
        cout<<ans+1;
    }else{
        cout<<0;
    }
    cout<<endl;
}