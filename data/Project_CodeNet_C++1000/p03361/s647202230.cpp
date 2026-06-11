#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int H,W;
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,-1,1,0};
    bool check;

    cin >> H >> W;
    
    vector<string> s(H);
    for(int i=0;i<H;i++) {
        cin >> s[i];
    }

    
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            if(s[i][j] == '#') {
                check = false;
                for(int k=0;k<4;k++) {
                    if((i+dx[k]) < 0 || (i+dx[k]) >= H || (j+dy[k]) < 0 || (j+dy[k]) >= W) continue;
                    if(s[i+dx[k]][j+dy[k]] == '#')check = true;
                }
                if(!check) {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }

    cout << "Yes\n";
    return 0;
}
