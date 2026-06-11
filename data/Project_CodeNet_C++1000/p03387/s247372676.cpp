#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    int sum = a+b+c;
    int m = max(a,b);
    m = max(m,c);
    int m3 = m*3;
    if(sum %2 == m3%2) cout << (m3-sum)/2<<endl;
    else cout << (m3+3 - sum) / 2 << endl;
}