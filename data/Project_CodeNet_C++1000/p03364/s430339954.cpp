#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> vviNum(n,vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            vviNum[i][j] = str[j] - 'a';
        }
    }
    int nAns = 0;
    for(int k = 0; k < n; k++){
        bool bJudge = true;
        for(int i = 0; i < n - 1; i++){
            int iTmp = (i + k) % n;
            for(int j = i + 1; j < n; j++){
                int jTmp = (j + k) % n;
                if(vviNum[iTmp][j] != vviNum[jTmp][i]){
                    bJudge = false;
                    break;
                }
            }
            if(!bJudge){
                break;
            }
        }
        if(bJudge){
            nAns++;
        }
    }
  
    printf("%d", nAns * n);
    return 0;
}
