#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int c=max(a,b);
    int d=min(a,b);
    if((c-d)%2!=0 || n==2)
    {
        cout<<"Borys"<<endl;
    }
    else
    {
        cout<<"Alice"<<endl;
    }
    return 0;
}
