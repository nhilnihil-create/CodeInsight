/*input
3
-1 0
0 3
2 -1
*/ 
#include <bits/stdc++.h>
#define int int_fast64_t
using namespace std;
const int MX = 1010;
int X[MX], Y[MX];
main () {
    set<int> s;
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> X[i] >> Y[i];
        s.insert(abs(X[i] + Y[i]) % 2);
    }
    if(s.size() > 1) return cout << -1, 0;
    vector<int> v;
    if(*s.begin() == 0) v.push_back(1);
    v.push_back(1);
    for(int i = 1; i <= 30; i ++) v.push_back(1 << i);
    reverse(v.begin(), v.end());
    cout << v.size() << endl;
    for(auto it: v) cout << it << ' '; cout << endl;
    for(int i = 1; i <= n; i ++) {
        int x = 0, y = 0;
        for(auto it: v) {
            int a = abs(x + it - X[i]) + abs(y - Y[i]);
            int b = abs(x - it - X[i]) + abs(y - Y[i]);
            int c = abs(x - X[i]) + abs(y + it - Y[i]);
            int d = abs(x - X[i]) + abs(y - it - Y[i]);
            int m = min({a, b, c, d});
            if(m == a) {
                cout << 'R';
                x += it;
            }
            else if(m == b) {
                cout << 'L';
                x -= it;
            }
            else if(m == c) {
                cout << 'U';
                y += it;
            }
            else if(m == d) {
                cout << 'D';
                y -= it;
            }
        }
        cout << endl;
    }
}