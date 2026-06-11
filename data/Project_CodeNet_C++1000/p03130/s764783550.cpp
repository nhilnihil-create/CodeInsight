#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <map>
#include <stdlib.h>
#include <cctype>
#include <bitset>
using namespace std;
int main(){
    int i,p,P[5] = {},a;
    for(i = 0;i < 6;i++){
        cin >> p;
        P[p] += 1;
    }
    a = 0;
    for(i = 1;i < 5;i++){
        if(P[i] % 2 == 1){
            a++;
        }
    }
    if(a == 0 || a == 2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}