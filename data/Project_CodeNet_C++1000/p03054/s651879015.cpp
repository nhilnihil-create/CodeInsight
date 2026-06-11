#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int N = 200000;
int h, w, n, r, c;
string s, t;
map<char, int> dir;
int d[4];

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w >> n >> r >> c >> s >> t;
    dir['L'] = 0, dir['R'] = 1, dir['U'] = 2, dir['D'] = 3;
    
    for(int i = 0; i < n; ++i) {
        d[dir[s[i]]]++;
        if(c+d[1] > w || c-d[0] < 1 || r+d[3] > h || r-d[2] < 1) {
            cout << "NO\n";
            return 0;
        }
        
        if(t[i] == 'L') {
            if(c+d[1] > 1) d[1]--;
        } else if(t[i] == 'R') {
            if(c-d[0] < w) d[0]--;
        } else if(t[i] == 'U') {
            if(r+d[3] > 1) d[3]--;
        } else if(t[i] == 'D') {
            if(r-d[2] < h) d[2]--;
        }
    }
    
    cout << "YES\n";
    
    return 0;
}
