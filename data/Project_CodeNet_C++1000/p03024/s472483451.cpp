#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    rep(i, n) {
        if(s[i] == 'o') {
            ans++;
        }
    }
    ans = ans+15-n;
    if(ans>=8){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
