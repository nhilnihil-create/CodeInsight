#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
    int n;
    int a,b,c;
    cin >> n;
    if(n%10==1){
        a=9;
        n-=1;
    } else {
        a=1;
        n-=9;
    }
    if(n%100==10){
        b=90;
        n-=10;
    } else {
        b=10;
        n-=90;
    }
    if(n%1000==100){
        c=900;
        n-=100;
    } else {
        c=100;
        n-=900;
    }
    cout << a+b+c << endl;



}