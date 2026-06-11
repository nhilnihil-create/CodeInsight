#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n;
    bool ans=false;
    string s,t,c;
    cin>>s>>t;
    n=s.size();
    c=s;
    for(i=0;i<n;i++)
    {
        if(c==t)
        {
            ans=true;
            cout<<"Yes"<<endl;
            break;
        }
        else
        {
            for(j=0;j<n;j++)
            {
                if(j==0)
                    c[j]=s[n-1];
                else
                    c[j]=s[j-1];
            }
        }
        s=c;
    }
    if(!ans)
        cout<<"No"<<endl;
}
