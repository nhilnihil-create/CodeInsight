//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<vector<ll> > sum(n, vector<ll>(n, -1));
    vector<ll> ssum(n);
    rep(i, n) {
        rep(j, n-i) {
            if(!i) {
                sum[0][j] = a[j];
                ssum[j] = a[j];
            } else {
                sum[i][j+i] = sum[i-1][j+i-1]+a[j+i];
                ssum.push_back(sum[i][j+i]);
            }
        }
    }

    ll x = 0;
    int jj = 40;
    rep(i, 41) {
        ll x_ = x+(1LL<<jj-i);
        int cou = 0;
        rep(j, n*(n+1)/2) {
            if((x_ & ssum[j]) == x_) {
                cou++;
            }
        }
        if(cou >= k) {
            x = x_;
        }
    }
    
    cout << x << endl;
}