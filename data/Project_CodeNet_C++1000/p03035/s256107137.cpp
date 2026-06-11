#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a>=13)
    {
        cout<<b<<endl;
        return 0;
    }
    else if(a<=12 && a>=6)
        {
        cout<<b*0.5<<endl;
        return 0;
    }
    else

    {
        cout<<b*0<<endl;
        return 0;
    }
}
