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

    int N[4]={};
    for(int i=0;i<4;i++){
        cin>>N[i];
    }

    sort(N,N+4);
//1974
    if(N[0]==1
    &&N[1]==4
    &&N[2]==7
    &&N[3]==9){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


    return 0;
}