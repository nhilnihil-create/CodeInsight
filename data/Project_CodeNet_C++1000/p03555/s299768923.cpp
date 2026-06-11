#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[3],b[3];
    gets(a);
    gets(b);
    char ch=a[2];
    a[2]=a[0];
    a[0]=ch;
    for(int i=0;i<3;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<("NO\n");
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}