#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

const int dy[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dx[8] = {1, -1, 0, 1, -1, 0, -1, 1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(i,h) {
        rep(j,w){
            if(s[i][j]=='#') continue;
            int cnt = 0;
                rep(k,8) {
                    int nj = j + dx[k]; 
                    int ni = i + dy[k]; 
                    if(nj >= w || nj < 0 || ni >= h || ni < 0) continue;
                    if(s[ni][nj]=='#') cnt++;
                }
                
                char c = '0'+cnt;
                s[i][j] = c;
            
        }
    }
    rep(i,h) {
        cout << s[i] << endl;
    }
    return 0;
}