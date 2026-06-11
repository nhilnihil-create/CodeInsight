#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,x,s=0,k=0;
    cin>>n>>d>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<100;j++)
        {
            if((a[i]*j)+1<=d)
            {
                k++;
            }
            else{
               break;
            }
        }
        s=s+k;
        k=0;
    }
    cout<<s+n+x;
    return 0;
}
