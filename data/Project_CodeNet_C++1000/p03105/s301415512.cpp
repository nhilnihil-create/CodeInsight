#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int a, b, c;
    cin >> a >> b >> c;

    int cnt;
    cnt = b / a;
    if(c < cnt) cout << c << endl;
    else cout << cnt << endl;
    return 0;
}