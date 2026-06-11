#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<functional>
using namespace std;
typedef	long long int ll;

int main(){
    string s;
    int x, y;
    cin >> s >> x >> y;
    vector<int> xi;
    vector<int> yi;
    xi.push_back(0);
    yi.push_back(0);
    int restart = s.size();
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='F'){
            x--;
        }
        else{
            restart = i;
            break;
        }
    }
    int length = 0;
    bool dr = 0;//0はx方向
    int xmax = 0;
    int ymax = 0;
    for(int i = restart; i < s.size(); i++){
        if(s[i]=='F'){
            length++;
        }
        else{
            if(dr==0){
                dr = 1;
                xi.push_back(2*length);
                xmax += 2*length;
                x += length;
                length = 0;
            }
            else{
                dr = 0;
                yi.push_back(2*length);
                ymax += 2*length;
                y += length;
                length = 0;
            }
        }
    }
    if(dr==0){
        xi.push_back(2*length);
        xmax += 2*length;
        x += length;
    }
    else{
        yi.push_back(2*length);
        ymax += 2*length;
        y += length;
    }
    if(x > xmax || x < 0){
        cout << "No" << endl;
        return 0;
    }
    if(y > ymax || y < 0){
        cout << "No" << endl;
        return 0;
    }
    bool dpx[xi.size()][xmax+1];
    bool dpy[yi.size()][ymax+1];
    for(int i = 0; i < xi.size(); i++){
        for(int j = 0; j <= xmax; j++){
            if(i==0){
                if(xi[i]==j) dpx[i][j] = 1;
                else if(j==0) dpx[i][j] = 1;
                else dpx[i][j] = 0;
            }
            else{
                if(dpx[i-1][j]==1) dpx[i][j] = 1;
                else if(j-xi[i]>=0 && dpx[i-1][j-xi[i]]==1) dpx[i][j] = 1;
                else dpx[i][j] = 0;
            } 
        }
    }
    for(int i = 0; i < yi.size(); i++){
        for(int j = 0; j <= ymax; j++){
            if(i==0){
                if(yi[i]==j) dpy[i][j] = 1;
                else if(j==0) dpy[i][j] = 1;
                else dpy[i][j] = 0;
            }
            else{
                if(dpy[i-1][j]==1) dpy[i][j] = 1;
                else if(j-yi[i]>=0 && dpy[i-1][j-yi[i]]==1) dpy[i][j] = 1;
                else dpy[i][j] = 0;
            } 
        }
    }
    if(dpx[xi.size()-1][x]==1 && dpy[yi.size()-1][y]==1){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}