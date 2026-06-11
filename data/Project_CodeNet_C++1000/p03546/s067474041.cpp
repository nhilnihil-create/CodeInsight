#include <bits/stdc++.h>
using namespace std;

#define abs(a) ((((a) < 0)) ? (-(a)) : (a))
#define min(a,b) (((a) > (b)) ? (b) : (a))
int main(void) {
    int64_t H,W;
    vector<vector<int64_t>> v(10,vector<int64_t>(10));
    int64_t wall;
    int64_t sum = 0;
    cin >> H >> W;

    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            cin >> v[i][j];
        }
    }

    for(int k=0;k<10;k++) {
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
            }
        }
    }

    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            cin >> wall;
            if(abs(wall) != 1) {
                sum += v[wall][1];
            }
        }
    }
    
    cout << sum << "\n";
    return 0;
}
