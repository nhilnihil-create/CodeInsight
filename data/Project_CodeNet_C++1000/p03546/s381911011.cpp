#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int h,w;cin >> h >> w;
    vector<vector<int>> g(10, vector<int>(10, INF));
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                g[j][k]=min(g[j][k], g[j][i]+g[i][k]);
            }
        }
    }

    vector<int> a(10);
    for(int i = 0; i < h*w; i++) {
        int x;cin >> x;
        if(x>=0) a[x]++;
    }

    int ans=0;
    for(int i = 0; i < 10; i++) {
        ans += a[i]*g[i][1];
    }

    cout << ans << endl;

    return 0;
}