#include <bits/stdc++.h>
#define ll long long
#define ch char
#define st string
using namespace std;
ll a,b,c,d,e,f,g,h;
st s;
void Urvatullo_Atoev()
{
    cin>>s;
    a=s[0]-'0';
    b=s[1]-'0';
    c=s[2]-'0';
    d=s[3]-'0';
    if(a+b+c+d==7)
    {
        cout<<a<<'+'<<b<<'+'<<c<<'+'<<d<<"=7";
    }
    else if(a+b+c-d==7)
    {
        cout<<a<<'+'<<b<<'+'<<c<<'-'<<d<<"=7";
    }
    else if(a+b-c-d==7)
    {
        cout<<a<<'+'<<b<<'-'<<c<<'-'<<d<<"=7";
    }
    else if(a-b-c-d==7)
    {
        cout<<a<<'-'<<b<<'-'<<c<<'-'<<d<<"=7";
    }
    else if(a+b-c+d==7)
    {
        cout<<a<<'+'<<b<<'-'<<c<<'+'<<d<<"=7";
    }
    else if(a-b+c+d==7)
    {
        cout<<a<<'-'<<b<<'+'<<c<<'+'<<d<<"=7";
    }
    else if(a-b-c+d==7)
    {
        cout<<a<<'-'<<b<<'-'<<c<<'+'<<d<<"=7";
    }
    else if(a-b+c-d==7)
    {
        cout<<a<<'-'<<b<<'+'<<c<<'-'<<d<<"=7";
    }
}
int main()
{
    Urvatullo_Atoev();
}
