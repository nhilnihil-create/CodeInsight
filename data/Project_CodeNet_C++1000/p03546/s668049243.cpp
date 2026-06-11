#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<int>> tfmat(10, vector<int> (10));

int const INF = 1 << 30;

int main(void){
    // Your code here!
    cin >> H >> W;
    for (int i=0; i<10; i++) for (int j=0; j<10; j++) cin >> tfmat[i][j];
    
    vector<vector<int>> grid(H, vector<int> (W));
    for (int i=0; i<H; i++) for (int j=0; j<W; j++) cin >> grid[i][j];
    

    for (int k=0; k<10; k++){
        for (int i=0; i<10; i++){
            for (int j=0; j<10; j++){
                tfmat[i][j] = min(tfmat[i][j], tfmat[i][k] + tfmat[k][j]);
            }
        }
    }
    
    int ans = 0;
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if (grid[i][j] != -1){
                ans += tfmat[grid[i][j]][1];
            }
        }
    }
    cout << ans << endl;
}
