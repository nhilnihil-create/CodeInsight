#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;



int main()
{
    string a,b;
    cin>>a>>b;
    bool flag=false;

    string c=a+a;
    if( c.find(b)!=string::npos)
        flag=true;
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
