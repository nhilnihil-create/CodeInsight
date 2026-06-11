#include <iostream>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    char n[4];
    ll ans=0;
    for(ll i=0;i<4;++i){
        cin>>n[i];
        if(n[i]=='2'){
            ans+=1;
        }
    }
    cout<<ans<<endl;
}