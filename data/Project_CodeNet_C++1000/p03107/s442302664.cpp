#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <algorithm>
using namespace std;
int main(void){
    string S; cin >> S;
    int a,b;
    a = count(S.begin(), S.end(), '0');
    b = count(S.begin(), S.end(), '1');
    cout << a + b - abs(a - b) << endl;
}