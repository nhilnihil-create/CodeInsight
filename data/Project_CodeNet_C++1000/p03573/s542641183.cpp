#include <iostream>
using namespace std;
int main(){
int x,y,z;
cin>>x>>y>>z;
if(x!=y && x!=z)
    cout<<x;
if(y!=x && y!=z)
    cout<<y;
if(z!=x && z!=y)
 cout<<z;
}
