#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    string s;
    cin >> s;
    int m = 0;
    int n = s.size();
    rep(i, n) {
        int t = 0;
        for(int j = i; j < n; j++) {
            if(s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T') {
                t++;
            } else {
                break;
            }
        }
        m = max(t,m);
    }
    cout << m <<endl;
}