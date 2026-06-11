#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> in(n);
    for(auto &i:in)
        scanf("%d",&i);
    sort(in.begin(),in.end());
    vector<int> x={0};
    x.reserve(n+1);
    const int inf=1e9;
    int res=inf;
    for(int i=0;i<n;++i)
    {
        int r=in[i];
        int s=24-r,p=inf,q=p;
        for(auto &j:x)
        {
            p=min(p,min(abs(j-r),24-abs(j-r)));
            q=min(q,min(abs(j-s),24-abs(j-s)));
        }
        if(p>q)
            x.push_back(r);
        else
            x.push_back(s);
        res=min(res,max(p,q));
    }
    printf("%d\n",res);
}
