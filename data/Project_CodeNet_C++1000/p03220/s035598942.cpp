#include<bits/stdc++.h>
using namespace std;
int main()
{
    float n,t,a,i;
    cin>>n>>t>>a;
    vector<float>v;
    for(i=0;i<n;i++)
    {
        float x;
        cin>>x;
        float l=t-(x*0.006);
        v.push_back(l);
    }
    float m=100000;
    for(i=0;i<v.size();i++)
    {
        m=min(m,abs(v[i]-a));
    }
    float d=100000;
    for(i=0;i<v.size();i++)
    {
        d=min(d,abs(v[i]-a));
        if(d==m)
        {
            cout<<i+1;
            return 0;
        }
    }

}
