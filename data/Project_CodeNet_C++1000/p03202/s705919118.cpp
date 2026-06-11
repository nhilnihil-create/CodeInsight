#include<bits/stdc++.h>
using namespace std;
struct sam
{
    long long x,y;
}p,q,temp;
long long a[200010];
vector <sam> v;
sam gouzao(long long xx,long long yy)
{
    sam temp;
    temp.x=xx;
    temp.y=yy;
    return temp;
}
long long s,t;
int main()
{
    int n,i,j,k,ans,l,r,mid;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    l=1;r=n-1;ans=n;
    while (l<=r)
    {
        bool flag=true;
        mid=(l+r)/2;
        v.clear();
        v.push_back(gouzao(1,a[1]));
        //cout<<mid<<endl;
        for (i=2;i<=n;i++)
        {
            //for (j=0;j<v.size();j++) cout<<v[j].x<<' '<<v[j].y<<endl;
            //cout<<i-1<<endl;
            if (!flag) break;
            if (a[i]>a[i-1])
            {
                t=v.size()-1;
                s=a[i]-a[i-1];
                if (v[t].x==1) v[t].y+=s;
                else v.push_back(gouzao(1,s));
            }
            else
            {
                s=a[i-1]-a[i];
                while (s>0)
                {
                    t=v.size()-1;
                    if (s>=v[t].y)
                    {
                        s-=v[t].y;
                        v.pop_back();
                    }
                    else
                    {
                        v[t].y-=s;
                        s=0;
                    }
                }
                t=v.size()-1;
                if (t==0&&v[t].x==mid)
                {
                    flag=false;
                    break;
                }
                if (v[t].x==mid)
                {
                    if (v[t-1].y>1)
                    {
                        v.push_back(gouzao(1,v[t].y));
                        v[t].x=v[t-1].x+1;
                        v[t].y=1;
                        v[t-1].y--;
                    }
                    else
                    {
                        v[t].x=1;
                        v[t-1].x++;
                        if (t>=2)
                        {
                            if (v[t-2].x==v[t-1].x)
                            {
                                v[t-2].y++;
                                v[t-1]=v[t];
                                v.pop_back();
                            }
                        }
                    }
                }
                else
                {
                    if (v[t].y>1)
                    {
                        v[t].y--;
                        v.push_back(gouzao(v[t].x+1,1));
                    }
                    else
                    {
                        v[t].x++;
                        if (t!=0)
                        {
                            if (v[t].x==v[t-1].x)
                            {
                                v[t-1].y++;
                                v.pop_back();
                            }
                        }
                    }
                }
            }
        }
        //for (j=0;j<v.size();j++) cout<<v[j].x<<' '<<v[j].y<<endl;
        //cout<<i-1<<endl;
        if (flag)
        {
            ans=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
