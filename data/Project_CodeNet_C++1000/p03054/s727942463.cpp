#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int h, w, n; cin >> h >> w >> n;
    int sr, sc; cin >> sr >> sc;
    --sr;
    --sc;
    string s, t; cin >> s >> t;
    char dirs[]={'L', 'U', 'R', 'D'};
    for (int i=0; i<4; ++i) {
        char d=dirs[i];
        char rd=dirs[(i+2)%4];
        int cur, lim;
        if (i%2==0) {
            cur=sc;
            lim=w;
        } else {
            cur=sr;
            lim=h;
        }
        if (i<2) {
            cur=lim-cur-1;
        }
        for (int k=0; k<n; ++k) {
            if (s[k]==d) {
                ++cur;
                if (cur>=lim) {
                    cout << "NO";
                    return 0;
                }
            }
            if (t[k]==rd) {
                if (cur>0) {
                    --cur;
                }
            }
        }
    }
    cout << "YES";
    return 0;
}