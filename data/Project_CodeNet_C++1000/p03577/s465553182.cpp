#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

string S;
int main (){
    cin >> S;
    int l = S.length()  - 8;
    cout << S.substr(0,l) << endl;
    return 0;
}