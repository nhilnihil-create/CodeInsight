#include<iostream>
#include<string>

using namespace std;
int main(){

int a,b,c,d,e,f;
string z,y;
cin>>z;
cin>>a;
b=z.length();
c=b-1;
e=a;
f=c/a;

cout<<z[0];
for(int i=0;i<f;i++)
{
    cout<<z[e];
    e=e+a;

}


return 0;}
