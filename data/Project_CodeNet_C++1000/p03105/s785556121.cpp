#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>

using namespace std;

int main(){
    int a,b,c;
    int ans = 0;
    cin >> a >> b >> c;
    if (b/a > c){
        cout << c << endl;
    }
    else{
        cout << b/a << endl;
    }
 }
