#include<iostream>
#include<string>
#include<stdio.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    string s;cin >> s;
    int y = 1,m= 1;
    if(s[2] > '1' ){y = 0;}
    if(s[2] == '1' && s[3] > '2'){y = 0;}
    if(s[2] == '0' && s[3] == '0'){y = 0;}

    if(s[0] > '1'){m = 0;}
    if(s[0] == '1' && s[1] > '2'){m = 0;}
    if(s[0] == '0' && s[1] == '0'){m = 0;}
    
    if(y == 1 && m == 1)cout << "AMBIGUOUS" << endl;
    else if(y==1)cout << "YYMM" << endl;
    else if(m==1)cout << "MMYY" << endl;
    else cout << "NA" << endl;
}