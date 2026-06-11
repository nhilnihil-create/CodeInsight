#include <bits/stdc++.h>
using namespace std;
 
int xs[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int ys[8] = {1, 1, 1, 0, 0, -1, -1, -1};
 
int h, w;
 
bool check(int x, int y){
    if (x >= 0 && x < h && y >= 0 && y < w){
        return true;
    }
    
    return false;
}
 
int main(){
    
    //int h, w;
    cin >> h >> w;
    
    string s;
    vector<vector<int>>arr(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        cin >> s;
        for(int j = 0; j < w; j++){
            s[j] == '.' ? arr[i][j] = 1 : arr[i][j] = 0; 
        }
    }
    string res;
    for(int i = 0; i < h; i++){
        res = "";
        for(int j = 0; j < w; j++){
            if(arr[i][j] == 1){
                int total = 0;
                for(int k = 0; k < 8; k++){
                    if(check(i+xs[k], j+ys[k]) && arr[i+xs[k]][j+ys[k]] == 0){
                        total += 1;
                    }
                }
                res += (char)(total + '0');
            }
            else { 
                res += '#'; 
            }
        }
        cout << res  << endl; 
    }
    
    
    return 0;
    
}