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
    ll n,a,b; cin>>n>>a>>b;
    cout<<min(a,b)<<' ';
    if(a+b>n){
        cout<<a+b-n<<endl;
    }else{
        cout<<0<<endl;
    }
}