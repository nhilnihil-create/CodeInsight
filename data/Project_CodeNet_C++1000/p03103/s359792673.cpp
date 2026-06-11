#include<bits/stdc++.h>
using namespace std;
#define llu unsigned long long int
int main()
{
    llu n,m,res=0,cnt=0,x,b,a,i;
    cin>>n>>m;
    vector<pair<long long int,long long int> > p(n);
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        p[i]=make_pair(a,b);
    }
    sort(p.begin(),p.end());
    for(i=0;i<n;i++)
    {
        x=m-cnt;
        if(p[i].second<=x)
            res+=(p[i].first*p[i].second),cnt+=p[i].second;
        else
            res+=(p[i].first*x),cnt+=x;
    }

    cout<<res<<endl;
    return 0;
}
