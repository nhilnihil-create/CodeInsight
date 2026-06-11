#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
 int a,b,c,d;
 cin>>a>>b>>c>>d;
 int x=0;
 if (abs(a-b)<=d){x++;}
 if (abs(b-c)<=d){x++;}
 if (x==2||abs(a-c)<=d){cout<<"Yes"<<endl;}
 else{cout<<"No"<<endl;}
 return 0;
}