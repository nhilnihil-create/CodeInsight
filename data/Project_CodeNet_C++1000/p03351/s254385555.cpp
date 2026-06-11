#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a, b,c,d;
    cin>>a>>b>>c>>d;

    if(abs(a-c)<=d) cout<<"Yes"<<endl;
    else{
        if(abs(a-b)<=d && abs(c-b)<=d) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

