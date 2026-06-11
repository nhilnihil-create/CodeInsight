#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int b=0, w=0, bb=0, ww=0, ans=1000000;

    for (int i=0; i<n; i++) {
        if (s.at(i) == '.') w++;
        else b++;
    }

    for (int i=0; i<n; i++) {
        if (s.at(i) == '.') {
            ww++;
        } else { 
            bb++;
        }
        if (ans > bb + w - ww) ans = bb + w - ww;
    }

    if (ans > w) ans = w;

    if (ans < 1000000){
        cout << ans << endl;
    } else cout << 0 << endl;
}