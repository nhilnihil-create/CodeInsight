#include <iostream>
#include <vector>
using namespace std;
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>>a(h,vector<char>(w));
    vector<vector<char>>ans(h,vector<char>(w));
    vector<int> dx{1,1, 1,0,0, -1,-1,-1};
    vector<int> dy{1,-1,0,1,-1,-1,0, 1};
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> a[i][j];
        }
    }
    
    int cnt=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(a[i][j]=='#'){
                ans[i][j]='#';
                continue;
            }else{
                for(int x=0; x<8; x++){
                    i += dx[x];
                    j += dy[x];
                    if(i>=0 && i<h && j<w && j>=0 && a[i][j]=='#') cnt++;
                    i -= dx[x];
                    j -= dy[x];
                }
            }
            
            ans[i][j] = cnt+48;
            cnt = 0;
        }
    }
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}