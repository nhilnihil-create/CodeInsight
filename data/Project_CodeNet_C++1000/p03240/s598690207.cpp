//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

struct pyramid {
    int x, y, h;
    pyramid(int i, int j, int k):x(i), y(j), h(k) {}
} ;

int main() {
    int n;
    cin >> n;
    vi x(n), y(n);
    vector<ll> h(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> h[i];
    }

    vector<pyramid> pp;

    rep(i, 101) {
        rep(j, 101) {
            ll h_ = -1LL;

            rep(ii, n) {
                if(h_ == -1LL) {
                    if(!h[ii]) {
                        if(ii && abs(i-x[ii]) + abs(j-y[ii]) > 1) break;
                        h_ = -(abs(i-x[ii]) + abs(j-y[ii]));
                    }
                    else h_ = abs(x[ii]-i) + abs(y[ii]-j) + h[ii];
                }
                if(h_< -1LL) {
                    if(!h[ii]) {
                        if(abs(i-x[ii]) + abs(j-y[ii]) < -h_) {
                            h_ = -(abs(i-x[ii]) + abs(j-y[ii]));
                        }
                    } else {
                        if(abs(i-x[ii]) + abs(j-y[ii])+h[ii] <= -h_) {
                            h_ = abs(i-x[ii]) + abs(j-y[ii])+h[ii];
                        } else {
                            break;
                        }
                    }
                } else if(h_ >= 0LL) {
                    if(!h[ii]) {
                        if(abs(i-x[ii]) + abs(j-y[ii]) < h_) break;
                    } else {
                        if(abs(i-x[ii]) + abs(j-y[ii]) + h[ii] != h_) break;
                    }
                } 
                if(h_ > 0 && ii == n-1) {
                    pp.push_back(pyramid(i, j, h_));
                }
            }
        }
    }

    for(pyramid xx:pp) {
        rep(i, n) {
            if(h[i] != max(0, xx.h-abs(xx.x-x[i]) - abs(xx.y-y[i]))) {
                break;
            }
            if(i == n-1) {
                cout << xx.x << ' ' << xx.y << ' ' << xx.h << endl;
                return 0;
            }
        }
    }
}