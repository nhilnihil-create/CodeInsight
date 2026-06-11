#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)
const ll INF = 1LL << 60;

int d[11][11];

int main(){
    int h,w;
    cin >> h >> w;
    rep(i,10){
        rep(j,10){
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < 10;i++){
        for (int j = 0; j < 10;j++){
            for (int k = 0;k < 10;k++){
                d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    int ans = 0;
    for (int i= 0;i < h;i++){
        for (int j = 0;j < w;j++){
            int tmp;
            cin >> tmp;
            if (tmp == -1) continue;
            else ans +=d[tmp][1];
        }
    }
    cout << ans << endl;
    
    
}