#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int d, n;
    cin >> d >> n;

    int ans;

    if (n != 100) ans = pow(100, d) * n;
    else ans= pow(100, d) * (n + 1);

    
    cout << ans << endl;


    return 0;
}