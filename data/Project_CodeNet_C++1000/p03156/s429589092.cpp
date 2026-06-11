#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,p[1000],i,j,k,c=0,ans=0;
    cin>>n>>a>>b;
    for(i=0;i<n;i++)
        cin>>p[i];
    sort(p,p+n);
    for(i=0;i<n;i++)
    {
        ans=0;
        if(p[i]<=a&&p[i]!=0)
        {
            for(j=i+1;j<n;j++)
            {
                if(p[j]>a&&p[j]<=b&&p[j]!=0)
                {
                    for(k=j+1;k<n;k++)
                    {
                        if(p[k]>b)
                        {
                            c++;
                            p[i]=0;
                            p[j]=0;
                            p[k]=0;
                            ans=1;
                            break;
                        }
                    }
                }
                if(ans==1)
                    break;
            }
        }
    }
    cout<<c<<endl;
}
