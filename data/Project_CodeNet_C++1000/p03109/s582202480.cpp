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
    string t;cin >> t;
    string ty,tm,td={};
    int j = 0;
    for(int i = 0;i < t.size();i++){
        if(t[i] =='/'){
            j++;
            continue;
        }
        if(j == 0)ty += t[i];
        else if(j == 1)tm += t[i];
        else td += t[i];
    }
    int y = stoi(ty);
    int m = stoi(tm);
    int d = stoi(td);
    if(y > 2019){cout << "TBD" << endl;}
    else if(m > 4){cout << "TBD" << endl;}
    else if(d > 30){cout << "TBD" << endl;}
    else cout << "Heisei" << endl;

}