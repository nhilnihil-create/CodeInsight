#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<cmath>
#include<vector>
#include<map>
#include<random>
#include<sstream>
using namespace std;

int main(){
    int N,T;cin >> N >> T;
    int c[1000],t[1000] = {};
    int f = 0;
    int m = 1000;
    int mId = 0;
    for(int i = 0;i < N;i++){
        cin >> c[i] >> t[i];
        if(T >= t[i]){f = 1;}
        if(m >= c[i] && t[i] <= T){
            m =c[i];
            mId = i;
        }
    }
    if(f == 0)cout << "TLE" << endl;
    else cout << m << endl;

    

}