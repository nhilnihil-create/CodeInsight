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
    char n[4];
    for(ll i=0;i<4;++i){
        cin>>n[i];
    }
    sort(n,n+4);
    bool t=false;
    if(n[0]-'0'==1){
        if(n[1]-'0'==4){
            if(n[2]-'0'==7){
                if(n[3]-'0'==9){
                    t=true;
                }
            }
        }
    }
    if(t==true){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}