#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//constexpr int SMAX = 8010;
int main(){
    string s;
    cin >> s;
    const int SMAX = s.size();

    int x, y;
    cin >> x >> y;
    
    bool xdir = true;
    vector<int> dx;
    vector<int> dy;
    int xc = 0;
    int yc = 0;
    for(size_t i = 0; i < s.size(); ++i){
        if(s[i] == 'F'){
            if(xdir) xc++;
            else yc++;
        }
        else {
            if(xdir){
                dx.push_back(xc);
                xc = 0;
            }
            else {
                dy.push_back(yc);
                yc = 0;
            }
            xdir = !xdir;
        }
    }
    if(xdir){
        dx.push_back(xc);
        xc = 0;
    }
    else {
        dy.push_back(yc);
        yc = 0;
    }

    vector<vector<bool>> dpx(SMAX, vector<bool>(SMAX * 2));
    dpx[1][SMAX + dx[0]] = true;
    for(size_t i = 2; i <= dx.size(); ++i){
        for(int j = 0; j < SMAX * 2; ++j){
            if(dpx[i-1][j]){
                int nx = j + dx[i-1];
                if(0 <= nx && nx < SMAX * 2){
                    dpx[i][nx] = true;
                }
                nx = j - dx[i-1];
                if(0 <= nx && nx < SMAX * 2){
                    dpx[i][nx] = true;
                }
            }
        }
    }
    
    vector<vector<bool>> dpy(SMAX, vector<bool>(SMAX * 2));
    dpy[0][SMAX] = true;
    for(size_t i = 1; i <= dy.size(); ++i){
        for(int j = 0; j < SMAX * 2; ++j){
            if(dpy[i-1][j]){
                int ny = j + dy[i-1];
                if(0 <= ny && ny < SMAX * 2){
                    dpy[i][ny] = true;
                }
                ny = j - dy[i-1];
                if(0 <= ny && ny < SMAX * 2){
                    dpy[i][ny] = true;
                }
            }
        }
    }
    if(dpx[dx.size()][x+SMAX] && dpy[dy.size()][y+SMAX]){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
}