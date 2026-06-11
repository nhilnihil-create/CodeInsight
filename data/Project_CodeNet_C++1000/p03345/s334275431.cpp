#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
#define pll pair<ll, ll>

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    vector<ll> nums = {A, B, C};
    if (abs(A - B) > (ll)pow(10, 18))
        cout << "Unfair" << endl;
    else {
        if (K % 2 == 1)
            cout << B - A << endl;
        else
            cout << A - B << endl;
    }
}