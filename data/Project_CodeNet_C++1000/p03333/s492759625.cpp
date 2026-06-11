#include<iostream>
#include<algorithm>
#include<cmath>
#define DN 100005
#define x first
#define y second
using namespace std;
int n,f,g,viz[DN],nr,poz,p,p1,p2;
pair<pair<int,int>,int>a[DN],b[DN];
long long rez,rez2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x.x>>a[i].x.y;
        a[i].y=i;
        b[i]=a[i];
        swap(b[i].x.x,b[i].x.y);
        a[i].x.x=-a[i].x.x;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        a[i].x.x=-a[i].x.x;
        swap(b[i].x.x,b[i].x.y);
    }
    poz=0;
    nr=n;
    p=p1=p2=1;
    while(nr--)
    {
       p=1-p;
       if(p==0)
       {
           while(viz[b[p1].y])
                p1++;
           viz[b[p1].y]=1;
           if(poz>=b[p1].x.x&&poz<=b[p1].x.y)
                continue;
            rez+=abs(b[p1].x.y-poz);
            poz=b[p1].x.y;
            continue;
       }
       while(viz[a[p2].y])
            p2++;
        viz[a[p2].y]=1;
        if(poz>=a[p2].x.x&&poz<=a[p2].x.y)
            continue;
        rez+=abs(a[p2].x.x-poz);
        poz=a[p2].x.x;
    }
    rez+=abs(poz);
    poz=0;
    nr=n;
    p=p1=p2=1;
    for(int i=1;i<=n;i++)
        viz[i]=0;
    while(nr--)
    {
       p=1-p;
       if(p==1)
       {
           while(viz[b[p1].y])
                p1++;
           viz[b[p1].y]=1;
           if(poz>=b[p1].x.x&&poz<=b[p1].x.y)
                continue;
            rez2+=abs(b[p1].x.y-poz);
            poz=b[p1].x.y;
            continue;
       }
       while(viz[a[p2].y])
            p2++;
        viz[a[p2].y]=1;
        if(poz>=a[p2].x.x&&poz<=a[p2].x.y)
            continue;
        rez2+=abs(a[p2].x.x-poz);
        poz=a[p2].x.x;
    }
    rez2+=abs(poz);
    cout<<max(rez2,rez);
}
