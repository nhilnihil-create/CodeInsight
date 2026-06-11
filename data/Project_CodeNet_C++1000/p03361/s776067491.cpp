#include <iostream>
#include <vector>
using namespace std;
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>>vec(h,vector<char>(w));
    vector<int>dx{ 0, 1,  0, -1};
    vector<int>dy{ 1, 0, -1,  0};
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> vec[i][j];
        }
    }
    bool flg=1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(vec[i][j]=='#'){
                for(int t=0; t<4; t++){
                    if(i+dx[t]>=0 && i+dx[t]<h && j+dy[t]>=0 && j+dy[t]<w && vec[i+dx[t]][j+dy[t]]=='#'){
                        flg=0;
                    }
                }
                if(flg){
                    puts("No");
                    return 0;
                }
                flg = 1;
            }
        }
    }
    puts("Yes");
    return 0;
}