#include<bits/stdc++.h>
using namespace std;
vector<int>v;
main()
{
	int t,p;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
    {
        scanf("%d",&p);
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    int mx=0,pos=0;
    for(int i = 0;i < t-1;i++)
    {
        if(mx<min(v[t-1]-v[i],v[i]))
        {
            pos=i;
            mx=min(v[t-1]-v[i],v[i]);
        }
    }
    printf("%d %d",v[t-1],v[pos]);
}
