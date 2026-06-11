#include<bits/stdc++.h>
using namespace std;
int main() 
{

int A,B,x,y,z,i,j;
cin>>A>>B;
x=A+B;
y=A-B;
z=A*B;
i=max(x,y);
j=max(y,z);
cout<<max(i,j)<<endl;

return 0;
}