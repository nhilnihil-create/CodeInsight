#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    string x;
    cin >> x;
    bool z = true;
    int a = 0;
    for(int i = 0; i < x.length(); i++){
        if(x[i] != '9'){
            z = false;
        }
        a += x[i] - '0';
    }
    if(z){
        cout << x.length()*9 << endl;
    }else if(x.length() == 1){
        cout << (x[0] - '0') << endl;
    }else if(x[0] == '1'){
        int b = (x.length() - 1)*9;
        if(a > b) cout << a << endl;
        else cout << b << endl;
    }else{
        int b = (x.length() - 1)*9 + (x[0] - '1');
        if(a > b) cout << a << endl;
        else cout << b << endl;
    }
    return 0;
}