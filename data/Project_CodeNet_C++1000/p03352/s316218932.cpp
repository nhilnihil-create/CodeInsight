#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    int X;
    cin >> X;
    vector<int> A;
    for (int i = 1; i <= X; i++) {
        for (int j = 2; j <= 20; j++) {
            ll num = pow(i, j);
            if (num > X)
                break;
            else
                A.push_back(num);
        }
    }

    ll ans = *max_element(all(A));
    cout << ans << endl;
}