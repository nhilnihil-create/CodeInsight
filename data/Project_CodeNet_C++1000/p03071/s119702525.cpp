#include<bits/stdc++.h>
using namespace std;
int main(void){
int a,b;cin>>a>>b;
cout<<max(max(a+(a-1),a+b),max(b+(b-1),a+b))<<endl;
return 0;}
