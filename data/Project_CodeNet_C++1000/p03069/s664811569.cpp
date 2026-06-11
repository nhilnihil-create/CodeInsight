#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> bsum(n+2, 0);
    vector<int> wsum(n+2, 0);
    for(int i = 0; i < n; ++i) {
        if(s[i] == '#') bsum[i+1]++;
        else wsum[i+1]++;
    }
    for(int i = 0; i < n; ++i) {
        bsum[i+1] += bsum[i];
        wsum[i+1] += wsum[i];
    }

    /*for(int i = 0; i <= n; ++i) {
        cout << bsum[i] << " ";
    }
    cout << endl;
    for(int i = 0; i <= n; ++i) {
        cout << wsum[i] << " ";
    }
    cout << endl;*/

    int ans = 1e9;
    chmin(ans, bsum[n]-bsum[0]);
    chmin(ans, wsum[n]-wsum[0]);
    for(int i = 0; i < n; ++i) {
        if(s[i] == '#') {
            int ch = (bsum[i]-bsum[0])+(wsum[n]-wsum[i]);
            chmin(ans, ch);
        }
    }
    cout << ans << endl;
}