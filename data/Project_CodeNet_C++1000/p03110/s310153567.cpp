#include<stdio.h>
#include<iostream>
#include<vector>
#include <fstream>
#include<math.h>
#include <numeric>
#include<algorithm>
#include <stdlib.h>
# include <map>

using namespace std;

int main(){
    int n;
    double tmp;
    string tmp2;
    double ans = 0;
    cin >> n;
    for(int i = 0 ;i < n ; i++){
        cin >> tmp >> tmp2;
        if (tmp2 == "JPY"){
            ans += tmp;
        }
        else{
            ans += tmp*380000.0;
        }
    }
    cout <<  ans << endl;
}
