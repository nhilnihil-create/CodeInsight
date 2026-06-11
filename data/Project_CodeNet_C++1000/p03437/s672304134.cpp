#include <iostream>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    ll x,y;
    cin>>x>>y;
    ll i=1;
    if(x%y!=0){
        cout<<x*(y+1)<<endl;
    }else{
        cout<<-1<<endl;
    }
}