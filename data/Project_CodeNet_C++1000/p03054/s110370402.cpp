//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int sr, sc;
    cin >> sr >> sc;
    string s, t;
    cin >> s >> t;

    vi vs(4);
    bool check = true;
    rep(i, n) {
        if(s[i] == 'L') {
            vs[0]++;
        }
        if(s[i] == 'R') {
            vs[1]++;
        }
        if(s[i] == 'U') {
            vs[2]++;
        }
        if(s[i] == 'D') {
            vs[3]++;
        }
        if(vs[0] >= sc) check = false;
        if(vs[2] >= sr) check = false;
        if(vs[1] >= w-sc+1) check = false;
        if(vs[3] >= h-sr+1) check = false;
        if(t[i] == 'L') {
            vs[1]--;
            if(sc + vs[1] == 0) vs[1] = 1-sc; 
        }
        if(t[i] == 'R') {
            vs[0]--;
            if(sc - vs[0] == w+1) vs[0] = sc-w;
        }
        if(t[i] == 'U') {
            vs[3]--;
            if(sr + vs[3] == 0) vs[3] = 1-sr;
        }
        if(t[i] == 'D') {
            vs[2]--;
            if(sr - vs[2] == h+1) vs[2] = sr-h;
        }
        
    }

    
    

    cout << (check ? "YES":"NO") << endl;
}