#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,s,m,p;
    cin>>a>>b;
    s=a+b;
    m=a*b;
    p=a-b;
    if(s>=m && s>=p){
        cout<<s<<endl;
    }
    else if(m>=p && m>=s){
        cout<<m<<endl;
    }
    else{
        cout<<p<<endl;
    }
    return 0;
}

