#include<bits/stdc++.h>

using namespace std;

using ll = long long;

std::vector<std::vector<ll>> d;

void warshall_floyd(int n){
    for(int i=0; i<n; i++){
        for(int j= 0; j<n; j++){
            for(int k = 0; k<n; k++){
                d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
}

int main(){
    int h,w; cin >> h >> w;
    d.resize(10);
    for(int i = 0; i<10; i++){
        d[i].resize(10);
        for(int j = 0; j<10; j++){
            cin >> d[i][j];
        }
    }
    warshall_floyd(10);
    int ans = 0;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<w; j++){
            int a;
            cin >> a;
            if(a==-1) continue;
            ans += d[a][1];
        }
    }
    cout << ans << endl;
}