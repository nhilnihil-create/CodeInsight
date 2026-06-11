#include <iostream>
#include<cmath>
using namespace std;
long long n,a,b,c;
int main(){
cin>>n;
while(n--){
cin>>a>>b;
c=sqrt(a*b);
cout<<(a*b-(a!=b))/c+c-2<<endl;}}
