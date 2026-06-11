#include <iostream>
#include <string>
using namespace std;

int main()
{
 int x, y, z ;
 cin>>x>>y>>z;
 if(x==y){
    cout<<z;
 }
 if(x==z){
    cout<<y;
 }
 if(y==z){
    cout<<x;
 }
    return 0;
}
