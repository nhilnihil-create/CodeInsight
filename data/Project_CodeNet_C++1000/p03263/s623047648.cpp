#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w, 0));
    int atmp;
    for(int ih=0;ih<h;ih++) {
        for(int iw=0;iw<w;iw++) {
            cin >> atmp;
            a.at(ih).at(iw) = atmp;
        }
    }

    int iw=0, ihbfr=0, iwbfr=0, ihnow, iwnow, n=0;
    vector<vector<int>> ans(h*w, vector<int>(4, 0));
    for(int ih=0;ih<h;ih++) {
        iw = 0;
        while(iw<w) {
            if(ih==0&&iw==0) {
                iw++;
                continue;
            }
            if(ih%2==0) {
                ihnow = ih;
                iwnow = iw;
            }
            else {
                ihnow = ih;
                iwnow = w-iw-1;
            }
            if(a.at(ihbfr).at(iwbfr)%2==1) {
                a.at(ihbfr).at(iwbfr)--;
                a.at(ihnow).at(iwnow)++;
                ans.at(n).at(0) = ihbfr+1;
                ans.at(n).at(1) = iwbfr+1;
                ans.at(n).at(2) = ihnow+1;
                ans.at(n).at(3) = iwnow+1;
                n++;
            }
            iw++;
            ihbfr = ihnow;
            iwbfr = iwnow;
        }
    }

    cout << n << endl;
    for(int in=0;in<n;in++) {
        cout << ans.at(in).at(0) << " " << ans.at(in).at(1) << " " << ans.at(in).at(2) << " " << ans.at(in).at(3) << endl;  
    }

    return 0;
}
