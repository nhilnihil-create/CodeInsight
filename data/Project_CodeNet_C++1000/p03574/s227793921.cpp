#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector <string> A(H);
    for (int i=0; i<H; i++){
        cin >> A[i];
    }
    int dx[8]={0,0,-1,-1,-1,1,1,1};
    int dy[8]={-1,1,-1,0,1,-1,0,1};
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            int count=0, x, y;
            if (A[i][j]=='#') continue;
            for (int k=0; k<8; k++){
                x=j+dx[k];
                y=i+dy[k];
                if (x<0 || x>=W) continue;
                if (y<0 || y>=H) continue;
                if (A[y][x]=='#') count++;
            }
            A[i][j]=char(count+'0');
        }
    }
    for (int i=0; i<H; i++){
        cout << A[i]<< endl;
    }
}
