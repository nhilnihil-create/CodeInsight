#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, sl, sr;
    cin >> s;

    string ss;
    for (int i=0; i<s.size(); i++) {
        if (s.at(i) != 'x') {
            ss += s.at(i);
        }
    }

    int ans=0;

    for (int i=0; i<ss.size()/2; i++) {
        sl += ss.at(i);
        sr += ss.at(ss.size()-1-i);
    }
    if (sl == sr) {
        int r=s.size()-1, l=0;
        while (l<=r) {
            if (s.at(l) == s.at(r)) {
                l++;
                r--;
            } else if (s.at(l) == 'x') {
                ans++;
                l++;
            } else {
                ans++;
                r--;
            }
        }
    } else ans = -1;
    

    cout << ans << endl;
}