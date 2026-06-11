#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    
    vector<vector<char>> grid(h+2,vector<char>(w+2, '.'));
    for (int i = 1; i <= h; i++){
      for (int j = 1; j <= w; j++){
        cin >> grid.at(i).at(j);
      }
    }

    const int dy[4]={0,1,0,-1};
    const int dx[4]={1,0,-1,0};

    bool can=true;
    
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            if(grid.at(i).at(j)=='#' && grid.at(i+1).at(j)=='.' && grid.at(i).at(j+1)=='.' && grid.at(i-1).at(j)=='.' && grid.at(i).at(j-1)=='.'){
                can=false;
                break;
            }
        }
        if(!can){
            break;
        }
    }
    if(can){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
}