#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int n;
    cin >> n;
    vector<ll> l(n+1);
    rep(i, n+1) {
        if (i == 0) l[i]= 2;
        else if (i == 1) l[i] = 1;
        else l[i] = l[i-1] + l[i-2];
    }
    cout << l[n] << endl;
}