#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <iostream>
using namespace std;
 
int gcd(int x,int y){
    if(y==0)return x;

    return gcd(y,x%y);
}
int lcm(int x,int y){
    return x*y/gcd(x,y);
}

int main(){

    int c[5]={0,0,0,0,0},a;

    for(int i=0;i<6;i++){
        cin>>a;
        c[a]++;
    }

    for(int i=1;i<=4;i++){
        if(c[i]>2){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

    return 0;
}