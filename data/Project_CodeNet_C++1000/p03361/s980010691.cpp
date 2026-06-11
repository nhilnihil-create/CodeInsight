#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    
    vector<vector<char>> grid(h,vector<char>(w));
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        cin >> grid.at(i).at(j);
      }
    }

    const int dy[4]={0,1,0,-1};
    const int dx[4]={1,0,-1,0};
    
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if(grid.at(i).at(j)=='#'){
                bool can=false;
                for (int k = 0; k < 4; k++){
                    int ny=i+dy[k];
                    int nx=j+dx[k];
                    if(0<=ny && ny<h && 0<=nx && nx<w){
                        if(grid.at(ny).at(nx)=='#'){
                            can=true;
                        }
                    }
                }
                if(!can){
                    cout << "No" << endl;
                    exit(0);
                }
            }
        }
    }

    cout << "Yes" << endl;
    
}