#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,p,c=0;
    vector<int>v,v1;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    p=sqrt(v[0]);
    for(int i=p; i>=1; i--)
    {
        if(v[0]%i==0)
        {
            v1.push_back(i);
            v1.push_back(v[0]/i);
        }
    }
    p=sqrt(v[t-1]);
    for(int i=p; i>=1; i--)
    {
        if(v[t-1]%i==0)
        {
            v1.push_back(i);
            v1.push_back(v[t-1]/i);
        }
    }
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    for(int i=0; i<v1.size(); i++)
    {
        c=0;
        for(int j=0; j<t; j++)
        {
            if(v[j]%v1[i]!=0)
            {
                c++;
                if(c==2)
                    break;
            }
        }
        if(c==1 || c==0)
        {
            cout<<v1[i]<<endl;
            break;
        }
    }
}
