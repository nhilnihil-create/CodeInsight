#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    int A[H][W];
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> A[i][j];
        }
    }    
    int cnt = 0;
    vector< pair< pair<int, int>, pair<int, int> > > ans;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(i == H-1 && j == W-1) continue;
            if(A[i][j] % 2 == 1){
                if(j < W-1) {
                    ans.push_back({{i+1, j+1}, {i+1, j+2}});
                    A[i][j+1]++;
                }
                else{
                    ans.push_back({{i+1, j+1}, {i+2, j+1}});
                    A[i+1][j]++;
                }
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    for(auto l : ans){
        cout << l.first.first << " " << l.first.second << " " << l.second.first << " " << l.second.second << endl;
    }    
    return 0;
}