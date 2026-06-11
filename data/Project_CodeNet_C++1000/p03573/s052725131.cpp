#include <iostream>
#include <string>
using namespace std;
string arr[20];
int main()
{
int a,b,c;
cin>>a>>b>>c;
if (a!=b&&a!=c){
cout<<a;
}
else if (b!=a&&b!=c){
cout<<b;
}
else{
cout<<c;
}
 return 0;
}