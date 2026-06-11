#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,i=0,t,m=0;
    cin>>a>>b>>c;
    vector<int>v;
    vector<int>v1;
    vector<int>w;
    for(int i=1;i<=a;i++)
    {
        if(a%i==0)
            v.push_back(i);
    }
    for(int j=1;j<=b;j++)
    {
        if(b%j==0)
            v1.push_back(j);
    }
    if(a>b)
    {
        while(i<v1.size())
        {
            v.push_back(v1[i]);
            i++;
        }
        sort(v.begin(),v.end());
        while(m<v.size())
        {
            if(v[m]==v[m+1])
            {
                w.push_back(v[m]);
            }
            m++;
        }
        cout<<w[w.size()-c]<<endl;
    }
    else
    {
        while(i<v.size())
        {
            v1.push_back(v[i]);
            i++;
        }
        sort(v1.begin(),v1.end());
        while(m<v1.size())
        {
            if(v1[m]==v1[m+1])
            {
                w.push_back(v1[m]);
            }
            m++;
        }
        cout<<w[w.size()-c]<<endl;
    }
}
