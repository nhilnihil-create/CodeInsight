#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    ll x, y;
    cin >> x >> y;
    ll cnt = 0;
    ll mul = x;
    while (x <= y) {
        x *= 2;
        cnt++;
    }
    cout << cnt << endl;
}