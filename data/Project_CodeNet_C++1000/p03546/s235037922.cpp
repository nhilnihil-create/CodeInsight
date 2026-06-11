#include <iostream>
#include <vector>
using namespace std;

int search(int start, int goal, int mincost){

}

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> c(10, vector<int>(10));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) cin >> c[i][j];
    }

    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cin >> a[i][j];
    }

    vector<int> cost(10, 0);
    for(int i = 0; i < 10; i++){
        cost[i] = c[i][1];
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(j == k) continue;
                if(cost[j] > c[j][k] + cost[k]) cost[j] = c[j][k] + cost[k];
            }
        }
    }

    long long int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!(a[i][j] == 1 || a[i][j] == -1)) ans += cost[a[i][j]];
        }
    }

    cout << ans << endl;
    return 0;
}