#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int h,w;cin >> h >> w;
    vector<vector<bool>> a(h+2, vector<bool>(w+2, false));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char x;cin >> x;
            if(x=='#') a[i+1][j+1]=true;
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(a[i+1][j+1] && !a[i][j+1] && !a[i+1][j] && !a[i+2][j+1] && !a[i+1][j+2]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}