#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
int a,b,x;
cin>>a>>b>>x;
if(a>x) cout<<"NO";
if(a==x) cout<<"YES";
if(a<x){
if((a+b)>=x){
    cout<<"YES";
}
else cout<<"NO";
}

return 0;
}