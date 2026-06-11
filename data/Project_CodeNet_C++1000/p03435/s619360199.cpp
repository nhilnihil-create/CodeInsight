#include <bits/stdc++.h>
using namespace std;

int G[3][3]={};
int main(){
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cin >> G[i][j];
    bool ok = true;
    for(int i = 0; i < 2; i++){
        int c;
        for(int j = 0; j < 3; j++){
            if(j == 0) c = G[i][j] - G[i + 1][j];
            else if(c != G[i][j] - G[i + 1][j]) ok = false;
        }
    }
    for(int j = 0; j < 2; j++){
        int c;
        for(int i = 0; i < 3; i++){
            if(i == 0) c = G[i][j] - G[i][j + 1];
            else if(c != G[i][j] - G[i][j + 1]) ok = false;
        }
    }
    if(ok) puts("Yes");
    else puts("No");
}
