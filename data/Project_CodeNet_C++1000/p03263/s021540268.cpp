#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> P;
typedef pair<int, int> Pi;
int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H, vector<int> (W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> a[i][j];
    }
    int gu = 0, ki = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) {
            if(a[i][j] % 2 == 0) gu++;
            else ki++;
        }
    }
    int cnt = 0;
    queue<P> q;
    int flag = 0;
    for(int i = 0; i < H; i++){
        if(flag == 1) break;
        for(int j = 0; j < W; j++){
            int k;
            if(i % 2 == 0) k = j;
            else k = W - 1 - j;
            if(a[i][k] % 2 == 1) cnt++;
            if(cnt == ki){
                flag = 1;
                break;
            }
            if(cnt % 2 == 1){
                if(i % 2 == 0){
                    if(k == W - 1) q.push(P(Pi(i + 1, k + 1), Pi(i + 2, k + 1)));
                    else q.push(P(Pi(i + 1, k + 1), Pi(i + 1, k + 2)));
                }
                else{
                    if(k == 0) q.push(P(Pi(i + 1, k + 1), Pi(i + 2, k + 1)));
                    else q.push(P(Pi(i + 1, k + 1), Pi(i + 1, k)));
                }
            }
        }
    }
    cout << q.size() << endl;
    while(!q.empty()){
        P v = q.front();
        q.pop();
        Pi v1 = v.first, v2 = v.second;
        printf("%d %d %d %d\n", v1.first, v1.second, v2.first, v2.second);
    }
}