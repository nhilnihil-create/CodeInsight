
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<pair<long long,long long> >v;
vector<long long>vx,vy;
int main()
{
    //fastio;
    long long c,d,e,l,g,n,k,i,j,t,p,q,x,y,x1,y1,x2,y2;
    long long f=4000000000000000005,a,b,m;
    //cout<<f<<'\n';
    cin>>n>>k;
    for(i=0; i<n; i++)
    {
        cin>>c>>d;
        v.push_back({c,d});
        vx.push_back(c);
        vy.push_back(d);
    }
    if(k==1)
    {
        cout<<0<<'\n';
        return 0;
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            for(p=0; p<n; p++)
            {
                for(q=p+1; q<n; q++)
                {
                    x1=vx[i];
                    x2=vx[j];
                    y1=vy[p];
                    y2=vy[q];

                    a=x2-x1;
                    b=y2-y1;
                    m=a*b;
                    //cout<<m<<'\n';
                    g=0;
                    for(l=0; l<n; l++)
                    {
                        if(v[l].first>=x1&&v[l].first<=x2&&v[l].second>=y1&&v[l].second<=y2)
                            g++;
                    }
                    if(g>=k)
                    {
                        f=min(m,f);
                    }
                }
            }
        }
    }
    cout<<f<<'\n';
    return 0;
}
