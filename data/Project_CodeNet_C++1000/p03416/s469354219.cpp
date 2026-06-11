#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool rotation(int n) {
    int a;
    int b;
    int c;
    int d;
    a = n % 10;
    n /= 10;
    b = n % 10;
    n /= 100;
    c = n % 10;
    n /= 10;
    d = n % 10;
    if(a == d && b == c)
        return true;
    else
        return false;
}

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int ans = 0, a, b;
    cin >> a >> b;
    for(int i = a; i <= b; i++)
        if(rotation(i)){
            ans++;
        }

    cout << ans << endl;
}