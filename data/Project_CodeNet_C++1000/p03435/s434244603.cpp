#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  // input
    vector<vector<int>> c(4, vector<int>(4));
    for(int i = 1;i < 4 ; i++) {
        for(int j = 1; j < 4; j++){
            cin >> c[i][j];
        } 
    }

  // compute
    int sum; 
    sum = 0;
    set<int> st1;
    set<int> st2;
    set<int> st3;
    set<int> st4;
    bool p,q,r,s,t;
    

    for(int i = 1;i < 4; i++) {
        st1.insert(c[i][2] - c[i][1]);
        st2.insert(c[i][3] - c[i][2]);
    }
    for(int i = 1;i < 4; i++) {
        st3.insert(c[2][i] - c[1][i]);
        st4.insert(c[3][i] - c[2][i]);
    }

    for(int i = 1;i < 4 ; i++) {
        for(int j = 1; j < 4; j++){
            sum += c[i][j];
        } 
    }

    p = (st1.size() == 1);
    q = (st2.size() == 1);
    r = (st3.size() == 1);
    s = (st4.size() == 1);
    t = (sum % 3 == 0);

  // output  

    if(p && q && r && s && t){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}
