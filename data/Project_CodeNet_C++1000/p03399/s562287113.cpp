#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<=b && c<=d) cout<<a+c<<endl;
    else if(b<=a && c<=d) cout<<b+c<<endl;
    else if(a<=b && d<=c) cout<<a+d<<endl;
    else cout<<b+d<<endl;
    return 0;
}
