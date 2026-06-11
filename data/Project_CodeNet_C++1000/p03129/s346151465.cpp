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
    ll n,k;
    cin>>n>>k;
    ll flag;
    if(n%2==0){
        flag=n/2;
    }else{
        flag=n/2+1;
    }
    if(flag>=k){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}