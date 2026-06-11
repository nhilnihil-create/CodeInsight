#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    speed();
    int n;
    ll x;
    cin >> n >> x;
    ll A[n];
    rep(i, 0, n) cin >> A[i];
    sort(A, A+n);
    int ans = 0;
    rep(i, 0, n) {
        x -= A[i];
        if (x < 0) break;
        if (x >= 0) ans++;
    }
    if (x > 0) ans--;
    cout << ans << endl;
    return 0;
}