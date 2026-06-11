#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,c=0,a[100];
    double s=0,av,ch;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    av=(double)(s/n);
    ch=abs(av-a[0]);
    if(ch==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    for(i=1; i<n; i++)
    {
        if(abs(av-a[i])==0)
        {
            cout<<i<<endl;
            return 0;
        }
        else
        {
            if(abs(av-a[i])<ch)
            {
                ch=abs(av-a[i]);
                c=i;
            }
        }
    }
    cout<<c<<endl;
}
