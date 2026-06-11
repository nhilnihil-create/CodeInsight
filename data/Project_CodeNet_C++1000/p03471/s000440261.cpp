#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n, Y;

int main() {
    cin >> n >> Y;
    for(int x = 0; x <= n; ++x) {
        for(int y = 0; x+y <= n; ++y) {
            int z = n - (x+y);
            int sum_cost = 10000*x + 5000*y + 1000*z;
            if(sum_cost == Y) {
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}