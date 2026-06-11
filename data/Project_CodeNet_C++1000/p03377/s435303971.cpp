#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
int main(){
    int a,b,x;
    cin>>a>>b>>x;
    if(a>x) cout<<"NO"<<endl;
    else if(a+b<x) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    
    return 0;
}