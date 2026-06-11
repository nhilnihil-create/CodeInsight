#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int func(int x) {
    if(x % 100 != 0)
        return 0;

    return func(x / 100) + 1;
}

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    string s;
    unsigned long k;
    cin >> s >> k;
    int onecnt = 0;
    rep(i, s.size()) {
        if(s[i] == '1') {
            onecnt++;
        } else {
            break;
        }
    }
    if(onecnt<k){
        cout <<s[onecnt]<<endl;
    }else{
        cout << 1 <<endl;
    }
}