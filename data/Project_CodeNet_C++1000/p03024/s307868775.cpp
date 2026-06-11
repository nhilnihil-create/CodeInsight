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

    int w;
    string S;
    cin>>S;

    for(int i=0;i<S.length();i++){
        if(S[i]=='o')w++;
    }

    w+=15-S.length();

    if(w>=8){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}