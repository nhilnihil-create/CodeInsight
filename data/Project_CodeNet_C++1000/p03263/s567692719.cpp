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



vvi a;
vvi tejun;

int main() {
    int h, w;
    cin >> h >> w;
    a.assign(h, vi(w));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
            a[i][j] &= 1;
        }
    }
    int i=0, j=0;
    int i_ =0, j_=-1;
    bool check = false;
    while(1) {
        if(!i && i_ == 1) {
            i_--;
            ++j;
        } else if(!i && !i_) {
            i++;
            j_++;
            if(h == 1) {
                i--;
                j++;
            }
        } else if(i == h-1 && i_ == h-2) {
            i_++;
            ++j;
        } else if(i == h-1 && i_ == i) {
            i--;
            ++j_;
        } else {
            i = 2*i-i_;
            i_ = (i+i_)/2;
        }
        
        if(j == w) break;
        if(check) {
            if(a[i_][j_]) check = false;
            else {
                tejun.push_back({i_, j_, i, j});
            }
        } else {
            if(a[i_][j_]) {
                check = true;
                tejun.push_back({i_, j_, i, j});
            }
        }
    }

    cout << (int)tejun.size() << endl;
    rep(i, tejun.size()) {
        rep(j, 3) {
            cout << ++tejun[i][j] << ' ';
        }
        cout << ++tejun[i][3] << '\n';
    } 
}