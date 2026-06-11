#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main(void){
    int a, b,x;
    cin>>a>>b>>x;
    if(a==x){
        cout<<"YES"<<endl;
    }else if(a<x&&a+b>x){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
