#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void){
    string str;
    cin >> str;
    cout << str.substr(0,str.size()-8) << endl;
    return 0;
}