#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<vector<int>> dist(10,vector<int>(10,0));
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cin >> dist[i][j];
        }
    }
    for (int k=0;k<10;k++){
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int sum = 0;
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            int a;
            cin >> a;
            if (a==-1) continue;
            if (a==1) continue;
            sum += dist[a][1];
        }
    }
    cout << sum << "\n";
}