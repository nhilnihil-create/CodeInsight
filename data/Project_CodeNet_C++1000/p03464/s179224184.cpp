#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
///////////////////////////////////////////////



int main() {
    int k; cin >> k;
    vector<ll> a(k);
    rep(i,k) cin >> a[i];
    ll mx = 2, mn = 2;
    repr(i,k-1) {
        if (mx%a[i]!=0 && mn%a[i]!=0 && mx/a[i] == mn/a[i]) {
            cout << -1 << endl;
            return 0;
        }
        mx = mx/a[i]*a[i]+a[i]-1;
        mn = (mn+a[i]-1)/a[i]*a[i];
    }
    cout << mn << " " << mx << endl;
    return 0;
}