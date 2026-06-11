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
using namespace std;

const double PI=acos(-1);

int main(){
    long a, b, c, k, d;
    cin >> a >> b >> c >> k;
    if(k%2 == 0){
        d = a - b;
    }else{
        d = b - a;
    }
    if(d > 1e18){
        cout << "Unfair" << endl;
    }else{
        cout << d << endl;
    }
    return 0;
}