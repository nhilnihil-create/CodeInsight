#include <iostream>
#include <algorithm>

using namespace std;

int l1_dist(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    int H, W, D;
    cin >> H >> W >> D;
    pair<int, int> loc[H * W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            int num;
            cin >> num;
            num--;
            loc[num] = {i, j};
        }
    }    
    int Q;
    cin >> Q;
    int L[Q], R[Q];
    for(int i=0; i<Q; i++){
        cin >> L[i] >> R[i];
        L[i]--; R[i]--;
    }
    int dist[D][H * W / D + 10];
    for(int i=0; i<D; i++){
        for(int j=0; i + j * D < H * W; j++){
            if(j == 0) dist[i][j] = 0;
            else{
                dist[i][j] = dist[i][j-1] + l1_dist(loc[i + j * D], loc[i + (j - 1) * D]);
            }
        }
    }
    
    for(int i=0; i<Q; i++){
        int offset = L[i] % D;
        cout << dist[offset][R[i]/D] - dist[offset][L[i]/D] << endl;
    }
    return 0;
}