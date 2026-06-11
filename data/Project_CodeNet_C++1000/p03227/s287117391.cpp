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
    string s;
    cin>>s;
    if(s.size()==2){
        cout<<s<<endl;
    }else{
        cout<<s[2]<<s[1]<<s[0]<<endl;
    }
}