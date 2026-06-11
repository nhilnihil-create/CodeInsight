#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;
vector<int> pcnt(110, 0);

int main() {
    cin >> n;
    pcnt.at(1) = 1;
    for(int i = 2; i <= n; ++i) {
        int check = i;
        for(int j = 2; j <= n; ++j) {
            while(check % j == 0) {
                pcnt.at(j)++;
                check /= j; 
            }
        }
    }

    int ans = 0;
    // x^2 * y^24
    int cnt2 = 0; int cnt24 = 0;
    for(int i = 0; i <= n; ++i) {
        if(pcnt.at(i) >= 24) cnt24++;
        if(pcnt.at(i) >= 2) cnt2++;
    }
    int fircnt = cnt24 * max(0, (cnt2-cnt24)) + cnt24 * max(0, (cnt24 - 1));

    // x^4 * y^14
    int cnt4 = 0; int cnt14 = 0;
    for(int i = 0; i <= n; ++i) {
        if(pcnt.at(i) >= 14) cnt14++;
        if(pcnt.at(i) >= 4) cnt4++;
    }
    int scdcnt = cnt14 * max(0, (cnt4-cnt14)) + cnt14 * max(0, (cnt14 - 1));

    // x^2 * y^4 * z^4
    int cntl2 = 0; int cntl4 = 0;
    for(int i = 0; i <= n; ++i) {
        if(pcnt.at(i) >= 4) cntl4++;
        if(pcnt.at(i) >= 2) cntl2++;
    }
    int thdcnt = max(0, (cntl2-cntl4)) * cntl4 * max(0, (cntl4 - 1)) / 2;
    if(cntl4 >= 3) thdcnt += cntl4 * ((cntl4 - 1) * (cntl4 - 2) / 2);

    // y^75
    int cnt74 = 0;
    for(int i = 0; i <= n; ++i) if(pcnt.at(i) >= 74) cnt74++;

    ans = fircnt + scdcnt + thdcnt + cnt74;
    cout << ans << endl;
}