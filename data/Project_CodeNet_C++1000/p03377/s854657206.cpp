#include <iostream>

using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    if((x+y)<z||x>z){cout<<"NO"<<endl;}
    else if((x+y)>=z&&x<=z){cout<<"YES"<<endl;}
    return 0;
}
