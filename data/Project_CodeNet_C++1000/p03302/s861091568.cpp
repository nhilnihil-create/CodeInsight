#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
    ll a,b; cin>>a>>b;
    if(a+b==15){
        cout<<'+'<<endl;
    }else if(a*b==15){
        cout<<'*'<<endl;
    }else{
        cout<<'x'<<endl;
    }
}