#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;

    int dif=abs(a-b);
    if(dif%2==0)
    {
        cout<<"Alice"<<endl;
    }
    else
    {
        cout<<"Borys"<<endl;
    }


}
