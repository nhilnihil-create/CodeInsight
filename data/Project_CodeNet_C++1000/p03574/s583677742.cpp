#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i < (int)(n);i++)

int main() {
    int h,w;
    char input;
    int map[50][50]={{0}};
    int out[50][50]={{0}};
    cin >> h >> w;
    for(int j=0;j<h;j++){
        for(int i=0;i<w;i++){
            cin >> input;
            if(input=='#'){
                map[i][j]=1;
            }
        }
    }
    for(int j=0;j<h;j++){
        for(int i=0;i<w;i++){
            if(map[i][j]==1){
                out[i][j]=9;
            }else{
                if(i!=0){
                    if(map[i-1][j]==1){
                        out[i][j]++;
                    }
                    if(j!=0){
                        if(map[i-1][j-1]==1){
                            out[i][j]++;
                        }
                    }
                    if(j!=h-1){
                        if(map[i-1][j+1]==1){
                            out[i][j]++;
                        }
                    }
                }
                if(i!=w-1){
                    if(map[i+1][j]==1){
                        out[i][j]++;
                    }
                    if(j!=h-1){
                        if(map[i+1][j+1]==1){
                            out[i][j]++;
                        }
                    }
                    if(j!=0){
                        if(map[i+1][j-1]==1){
                            out[i][j]++;
                        }
                    }
                }
                if(j!=h-1){
                    if(map[i][j+1]==1){
                        out[i][j]++;
                    }
                }
                if(j!=0){
                    if(map[i][j-1]==1){
                        out[i][j]++;
                    }
                }
            }
        }
    }

    for(int j=0;j<h;j++){
        for(int i=0;i<w;i++){
            if(out[i][j]==9){
                cout << '#';
            }else{
                cout << out[i][j];
            }
        }
        cout << endl;
    }
}