#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll a,b,c,d;
    a=(int)s[0]-48;
    b=(int)s[1]-48;
    c=(int)s[2]-48;
    d=(int)s[3]-48;
    if((a+b+c+d)==7)
        cout<<a<<"+"<<b<<"+"<<c<<"+"<<d<<"=7"<<endl;
    else if((a+b+c-d)==7)
        cout<<a<<"+"<<b<<"+"<<c<<"-"<<d<<"=7"<<endl;
    else if((a+b-c+d)==7)
        cout<<a<<"+"<<b<<"-"<<c<<"+"<<d<<"=7"<<endl;
    else if((a-b+c+d)==7)
        cout<<a<<"-"<<b<<"+"<<c<<"+"<<d<<"=7"<<endl;
    else if((a-b+c+d)==7)
        cout<<a<<"-"<<b<<"+"<<c<<"+"<<d<<"=7"<<endl;
    else if((a-b-c-d)==7)
        cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"=7"<<endl;
    else if((a+b-c-d)==7)
        cout<<a<<"+"<<b<<"-"<<c<<"-"<<d<<"=7"<<endl;
    else if((a-b-c+d)==7)
        cout<<a<<"-"<<b<<"-"<<c<<"+"<<d<<"=7"<<endl;
    else if((a+b-c+d)==7)
        cout<<a<<"+"<<b<<"-"<<c<<"+"<<d<<"=7"<<endl;
    else if((a-b+c-d)==7)
        cout<<a<<"-"<<b<<"+"<<c<<"-"<<d<<"=7"<<endl;
    return 0;
}