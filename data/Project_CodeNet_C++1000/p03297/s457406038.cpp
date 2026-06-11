//https://atcoder.jp/contests/agc026/tasks/agc026_b

#include<bits/stdc++.h>
using namespace std;

int t;
long long a, b, c, d;

void solve(){
    cin >> a >> b >> c >> d;
    if (a > c) a = c + 1 + (a - c - 1) % b;
    if (a < b) return void(cout << "No\n");
    if (b > d) return void(cout << "No\n");
    if (b <= c+1) return void(cout << "Yes\n");
    long long x = __gcd(d, b);
    a -= b;
    a = a + (c - a + x) / x * x;
    if (a < b) return void(cout << "No\n");
    cout << "Yes\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) solve();
}
