#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = max(a+b, max(2*a-1, 2*b-1));
    cout << ans << endl;
    return 0;
}