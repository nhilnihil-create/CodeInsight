#include <iostream>

using namespace std;

int main()
{
int n,b,a;
cin>>n;
b=n/1000;
b=b*1000;
b=n-b;
a=n/10;
if(b%111==0 || a%111==0){
    cout<<"Yes";
}
else{
    cout<<"No";
}
 return 0;
}
