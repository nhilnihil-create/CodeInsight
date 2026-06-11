#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
    //input
    int h,w;cin >> h >> w;
    vector<string> str(h);
    for(int i = 0; i < h; i++) cin >> str[i];
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h + 2, vector<int>(w + 2));
    vector<vector<int>> c(h + 2, vector<int>(w + 2));

    for(int i = 0;i < h; i++) {
        for(int j = 0; j < w ; j++){
           a[i][j] = 0;
        } 
    }
  
    for(int i = 0;i < h + 2; i++) {
        for(int j = 0; j < w + 2 ; j++){
           b[i][j] = 0;
           c[i][j] = 0;
        } 
    }  

    //compute
    for(int i = 0;i < h; i++) {
        for(int j = 0; j < w ; j++){
            if(str[i].at(j) == '#'){
                b[i + 1][j + 1] = 1;
            }    
        } 
    }

    for(int i = 0;i < h; i++) {
        for(int j = 0; j < w ; j++){
            if(b[i + 1][j + 1] == 0){
                c[i + 1][j + 1] += b[i][j]+b[i][j + 1]+ b[i][j + 2];
                c[i + 1][j + 1] += b[i + 1][j] + b[i + 1][j + 2];
                c[i + 1][j + 1] += b[i + 2][j] + b[i + 2][j + 1] + b[i + 2][j + 2];
            }else{
                c[i + 1][j + 1] = 100;
            }
        }
    } 

    //output
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(c[i + 1][j + 1] == 100){
                cout << '#';
            }else{
                cout << c[i + 1][j + 1];
            }
            if(j == w - 1){
                cout << endl;
            }
        }
    }    

}