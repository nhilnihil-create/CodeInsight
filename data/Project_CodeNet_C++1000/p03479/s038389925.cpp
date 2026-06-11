#include <bits/stdc++.h>
using namespace std;

long long X,Y;
int val=0;
int main (){
    cin>>X>>Y;
    while(Y>=X){
        val++;
        X*=2;
    }
   
    cout<<val;
    }
