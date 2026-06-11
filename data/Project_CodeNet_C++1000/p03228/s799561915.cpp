#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;
    rep(i, k) {
        if(i % 2 == 0) {
            if(a % 2 == 1) {
                a--;
            }
            a /= 2;
            b += a;
        }
        else{
            if(b % 2 == 1) {
                b--;
            }
            b /= 2;
            a += b;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}