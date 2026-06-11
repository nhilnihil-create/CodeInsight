#include <bits/stdc++.h>//復習必須
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
int main () {
    int N;
    long long top[5]={};
    long long answer=0;
    std::string str;
 
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str;
        if(str[0]=='M'){
            top[0]++;
        }
        else if(str[0]=='A'){
            top[1]++;
        }
        else if(str[0]=='R'){
            top[2]++;
        }
        else if(str[0]=='C'){
            top[3]++;
        }else if(str[0]=='H'){
            top[4]++;
        }
 
    }
 
    for(int i=0;i<=2;i++){
        for(int j=i+1;j<=3;j++){
            for(int k=j+1;k<=4;k++){
                answer+=top[i]*top[j]*top[k];
            }
        }
    }
    cout<<answer<<endl;
    return 0 ;
}

 
