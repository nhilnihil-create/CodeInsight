#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {

    double ans = 0.0;
    int n;
    cin >> n;

    rep(i,n) {
        double x;
        string s;
        cin >> x >> s;
        if (s == "JPY") ans += x;
        else ans += x*380000.0;
    }

    printf("%.8f\n", ans);
    
    return 0;
}