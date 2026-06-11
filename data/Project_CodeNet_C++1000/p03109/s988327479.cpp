#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>
#include <stdlib.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    if (s[5] == '1'){
        cout << "TBD" << endl;
    }
    else{
        if(s[6] - '0'>= 5){
            cout << "TBD" << endl;
        } 
        else{
            cout << "Heisei";
        }
    }
}
