#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    string s;
    cin >>s;
    int r=0,b=0;
    for(int i=0;i<n;i++){
        if(s.at(i) == 'R')r++;
        else b++;
    }
    if(r > b)cout << "Yes" << endl;
    else cout << "No" << endl;
 }