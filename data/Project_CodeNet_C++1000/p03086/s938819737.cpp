#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;

int main(){
    string S;  cin >>  S;
    int count=0,max=0;
    for(auto s: S){
        if(s=='A'||s=='G'||s=='C'||s=='T') {
            count++;
            if(count > max) max = count;
        }
        else count = 0;
    }
    cout << max << endl;
    return 0;
}