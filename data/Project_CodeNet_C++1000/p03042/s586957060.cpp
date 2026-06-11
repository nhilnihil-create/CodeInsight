#include<iostream>
#include <algorithm>
#include<cstdio>
#include<string>
#include<math.h>
#include<vector>
#include <queue>
#include <bits/stdc++.h>
#include <map>
#include <cmath>
#include <cctype>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
using namespace std;
typedef vector<vector<char>> field_t;

typedef pair<int, int> point_t;
vector<vector<pair<int,int>>> z(100010);


int main()
{
    string S;
    cin >> S;
    
    int U,D,i,y;
    y=stoi(S);
    U=y/100;
    D=y%100;
    if(D<13&&D>0){
        if(U<13&&U>0){
            cout << "AMBIGUOUS" << endl;
        }else{
            cout << "YYMM" << endl;   
        }
    }else{
       if(U<13&&U>0){
            cout << "MMYY" << endl;
        }else{
            cout << "NA" << endl;   
        } 
    }
        
    return 0;
}