#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vll a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    ll asum = accumulate(a.begin(), a.end(), 0LL);
    ll bsum = accumulate(b.begin(), b.end(), 0LL);
    
    ll cnt2 = 0, cnt1 = 0;
    rep(i, n) {
        if (a[i] > b[i]) {
            cnt1 += a[i]-b[i];
        } else if (a[i] < b[i]) {
            if ((b[i]-a[i])&1) {
                cnt2 += (b[i]-a[i]+1)/2;
                cnt1 += 1;
            } else {
                cnt2 += (b[i]-a[i])/2;
            }
        }
    }
    if (cnt2 <= bsum-asum && cnt1 <= bsum-asum) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}