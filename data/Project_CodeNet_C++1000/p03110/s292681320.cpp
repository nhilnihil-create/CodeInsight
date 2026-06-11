#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<cmath>
#include<vector>
#include<map>
#include<random>
#include<sstream>
using namespace std;

int main(){
    int n; cin >> n;
    double x[n];
    string u[n];
    for(int i = 0;i < n;i++){
        cin >> x[i] >> u[i];
    }
    double total = 0;
    for(int i = 0;i < n;i++){
        if(u[i] == "JPY"){
            total += x[i];
        }else{
            total += x[i]*380000.0;
        }
    }
    cout << total << endl;

}