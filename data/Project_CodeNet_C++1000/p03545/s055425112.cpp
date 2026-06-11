#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,d,x=0,y=0,x2=0,y2=0;
    string s;
    cin>>s;
    a=s[0]-'0';
    b=s[1]-'0';
    c=s[2]-'0';
    d=s[3]-'0';
    if(a+b+c+d==7){
        cout<<a;cout<<"+";
        cout<<b;cout<<"+";
        cout<<c;cout<<"+";
        cout<<d;cout<<"=7";
    }
    else if(a+b+c-d==7){
        cout<<a;cout<<"+";
        cout<<b;cout<<"+";
        cout<<c;cout<<"-";
        cout<<d;cout<<"=7";
    }
    else if(a+b-c+d==7){
        cout<<a;cout<<"+";
        cout<<b;cout<<"-";
        cout<<c;cout<<"+";
        cout<<d;cout<<"=7";
    }
    else if(a-b+c+d==7){
        cout<<a;cout<<"-";
        cout<<b;cout<<"+";
        cout<<c;cout<<"+";
        cout<<d;cout<<"=7";
    }
    else if(a+b-c-d==7){
        cout<<a;cout<<"+";
        cout<<b;cout<<"-";
        cout<<c;cout<<"-";
        cout<<d;cout<<"=7";
    }
    else if(a-b+c-d==7){
        cout<<a;cout<<"-";
        cout<<b;cout<<"+";
        cout<<c;cout<<"-";
        cout<<d;cout<<"=7";
    }
    else if(a-b-c+d==7){
        cout<<a;cout<<"-";
        cout<<b;cout<<"-";
        cout<<c;cout<<"+";
        cout<<d;cout<<"=7";
    }
    else if(a-b-c-d==7){
        cout<<a;cout<<"-";
        cout<<b;cout<<"-";
        cout<<c;cout<<"-";
        cout<<d;cout<<"=7";
    }
}
