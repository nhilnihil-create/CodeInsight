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
    int a, b, c, x; cin >> a >> b >> c >> x;
    int cnt = 0;
    rep(i, 0, a+1) {
        rep(j, 0, b+1) {
            rep(k, 0, c+1) {
                int t = i*500 + j*100 + k*50;
                if (t == x) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}