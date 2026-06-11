#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>=b && c>=d){
        cout<<b+d<<endl;
    }
    else if(b>=a && d>=c){
        cout<<a+c<<endl;
    }
    else if(a>=b && c<=d){
        cout<<b+c<<endl;
    }
    else {
        cout<<a+d<<endl;
    }

    return 0;
}

