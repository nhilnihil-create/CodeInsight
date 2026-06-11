#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int h,w; cin >> h >> w;
    queue<tuple<int,int,int>> q;
    vector<vector<bool>> reached(h, vector<bool>(w, false));
    int c=0;
    for (int i=0; i<h; ++i) {
        string s; cin >> s;
        for (int k=0; k<w; ++k) {
            if (s[k]=='#') {
                q.push(make_tuple(i,k,0));
                reached[i][k]=true;
                ++c;
            }
        }
    }
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    if (c==h*w) {
        cout << 0;
        return 0;
    }
    while(1) {
        tuple<int,int,int> f=q.front();
        int cst=get<2>(f);
        q.pop();
        for (int i=0; i<4; ++i) {
            int ny=get<0>(f)+dy[i];
            int nx=get<1>(f)+dx[i];
            if (nx>=0 && nx<w && ny>=0 && ny<h && !reached[ny][nx]) {
                q.push(make_tuple(ny,nx,cst+1));
                reached[ny][nx]=true;
                ++c;
                if (c==h*w) {
                    cout << cst+1;
                    return 0;
                }
            }
        }
    }
    return 0;
}