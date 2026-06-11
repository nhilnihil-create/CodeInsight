#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b;
    cin >> a >> b;

    int ans = -1;
    ans = max(ans, a+(a-1));
    ans = max(ans, a+b);
    ans = max(ans, b+(b-1));
    cout << ans << endl;
    return 0;
}