#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        int t=0;
        t=b/a;
        if(t<=c)
            cout<<t<<endl;
        else
            cout<<c<<endl;

    }
    return 0;
}
