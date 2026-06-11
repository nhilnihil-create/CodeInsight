#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b;
    char ch[100][100];
    for(int i=0; i<50; i++){
        for(int j=0; j<100; j++){
            ch[i][j] = '#';
        }
    }
    for(int i=50; i<100; i++){
        for(int j=0; j<100; j++){
            ch[i][j] = '.';
        }
    }
    cin >> a >> b;
    a--;
    b--;
    while(true){
        for(int y=0; y<50; y+=2){
            for(int x=0; x<100; x+=2){
                if(a>0){
                    ch[y][x] = '.';
                    a--;
                }
                else break;
            }
            if(a==0) break;
        }
        if(a==0) break;
    }
    while(true){
        for(int y=51; y<100; y+=2){
            for(int x=0; x<100; x+=2){
                if(b>0){
                    ch[y][x] = '#';
                    b--;
                }
                else break;
            }
            if(b==0) break;
        }
        if(b==0) break;
    }
    cout << "100 100" << endl;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            cout << ch[i][j];
        }
        cout << endl;
    }
}