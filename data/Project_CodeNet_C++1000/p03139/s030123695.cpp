//
//  main.cpp
//  countest
//
//  Created by Reza Godarzi on 11/29/1397 AP.
//  Copyright © 1397 w. All rights reserved.
//
#include <iostream>
#include <set>
#include<math.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std ;
const ll N=1e5+10;
#define needforspeed   ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int main(){
    needforspeed;
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<min(b,c)<<" ";
    if(a>=b+c){
        cout<<"0";
    }else{
        cout<<(b+c)-a;
    }
    
    
    
}
