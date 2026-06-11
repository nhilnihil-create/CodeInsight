#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
const int ddx[4] = {1,1,-1, -1};
const int ddy[4] = {1,-1,-1,1};
//////////////////////////////////

int main() {
    int a, b; cin >> a >> b;
    a--; b--;
    vector<string> s(100, string(100, '#'));
    for(int i=50; i<100; i++) {
        s[i] = string(100, '.');
    }

    for(int i=0; i<49; i+=2) {
        for(int j=0; j<100; j+=2) {
            if(a == 0) break;
            s[i][j] = '.';
            a--;
        }
    }
    for(int i=51; i<100; i+=2) {
        for(int j=0; j<100; j+=2) {
            if(b == 0) break;
            s[i][j] = '#';
            b--;
        }
    }
    cout << s.size() << " " << s[0].size() << endl;
    for(int i=0; i<100; i++) cout << s[i] << endl;

    return 0;
}

// EOF
