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

    int A,B;
    cin>>A>>B;

    if(B%A==0){
        cout<<A+B<<endl;
    }else{
        cout<<B-A<<endl;
    }

    return 0;
}