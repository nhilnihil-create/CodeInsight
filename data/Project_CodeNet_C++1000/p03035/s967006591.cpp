#include<bits/stdc++.h> 
using namespace std;

int main() {
    long long n,m;
    cin>>n>>m;
    if(n<=5){
        cout<<0;
    }else if(n>5&&n<=12){
        cout<<m/2;
    }else{
        cout<<m;
    }
}