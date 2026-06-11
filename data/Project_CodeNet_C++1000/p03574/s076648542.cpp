#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
using namespace std;
int main(){
    int H,W,i,j,q;
    cin >> H >> W;
    char S[H][W];
    char p[W];
    char c;
    for(i = 0;i < H;i++){
        cin >> p;
        for(j = 0;j < W;j++){
            S[i][j] = p[j];
        }
    }
    for(i = 0;i < H;i++){
        for(j = 0;j < W;j++){
            if(S[i][j] == '#'){
                if(j == W - 1){
                    printf("%c\n",'#');
                }
                else{
                    printf("%c", '#');
                }
            }
            else{
                q = 0;
                if(S[i - 1][j - 1] == '#' && i > 0 && j > 0){
                    q++;
                }
                if (S[i - 1][j] == '#' && i > 0){
                    q++;
                }
                if (S[i - 1][j + 1] == '#' && i > 0 && j < W - 1){
                    q++;
                }
                if (S[i][j - 1] == '#' && j > 0){
                    q++;
                }
                if (S[i][j + 1] == '#' && j < W - 1){
                    q++;
                }
                if (S[i + 1][j - 1] == '#' && i < H - 1 && j > 0){
                    q++;
                }
                if (S[i + 1][j] == '#' && i < H - 1){
                    q++;
                }
                if (S[i + 1][j + 1] == '#' && i < H - 1 && j < W - 1){
                    q++;
                }
                c = '0' + q;
                if (j == W - 1){
                    printf("%c\n",c);
                }
                else{
                    printf("%c",c);
                }
            }
        }
    }
}