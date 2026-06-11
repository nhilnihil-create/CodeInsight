#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    char c[h][w];
    for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin >> c[i][j];
    int dy[8]={-1,-1,-1,0,0,1,1,1};
    int dx[8]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
        if(c[i][j]=='#')cout << "#";
        else{
            int tmp=0;
            for(int k=0;k<8;k++){
                if(i+dy[k]>=0 && i+dy[k]<h && j+dx[k]>=0 && j+dx[k]<w){
                    if(c[i+dy[k]][j+dx[k]]=='#')tmp++;
                }
            }
            cout << tmp;
        }
    }
    cout << endl;
}
}