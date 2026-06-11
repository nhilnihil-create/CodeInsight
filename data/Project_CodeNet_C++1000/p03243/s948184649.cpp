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
    int n;cin >> n ;
    int t,h,o;
    t = n/100;
    h = n%100/10;
    o = n%10;
    int m;
    //cout << t << h <<  o << endl;
    if(t == h && t == o){cout << n;}
    else{
        for(int i = 999;i >= n;i-=111){
            m = i;  
        }
        cout << m << endl;
    }
}