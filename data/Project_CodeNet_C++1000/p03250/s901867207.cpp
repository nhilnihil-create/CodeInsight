#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
int main(){
    int a,b,c; cin>>a>>b>>c;
    int maxa=a;
    if(b>maxa) maxa=b;
    else if(c>maxa) maxa=c;
    if (maxa==a) cout<<a*10+b+c;
    else if(maxa==b) cout<<b*10+a+c;
    else if(maxa==c) cout<<c*10+a+b;
    return 0;
}
