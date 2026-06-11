#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >>d;
    string ans = "No\n";
    if (abs(a - c) <= d) ans = "Yes\n";
    if (abs(a - b) <= d && abs(b - c) <= d) ans = "Yes\n";
    cout << ans << endl;
}