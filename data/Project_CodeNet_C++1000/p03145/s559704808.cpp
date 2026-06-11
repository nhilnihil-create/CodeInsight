#include<iostream>
using namespace std;
int main ()
{
    int ab,bc,ca;
    int a,b,c;
    int area;
    cin>>ab>>bc>>ca;
    a=ab*ab;
    b=bc*bc;
    c=ca*ca;
    if(a+b==c )
    {
        area=0.5*ab*bc;
        cout<<area<<endl;
    }
 else  if(a+c==b )
    {
        area=0.5*ab*ca;
        cout<<area<<endl;
    }
    else if (c+b==a)
    {
        area = 0.5*bc*ca;
    cout<<area<<endl;
    }
    return 0;
}
