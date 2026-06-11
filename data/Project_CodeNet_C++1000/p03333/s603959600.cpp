#include<iostream>
#include<algorithm>
#include<cmath>
#define DN 100005
#define x first
#define y second
using namespace std;
int n,f,g,viz[DN],nr,poz,p,p1,p2;
typedef pair<pair<int,int>,int> pii;
pii a[DN],b[DN];
long long rez,rez2;
void solve(pii a[DN],int &p,int type,long long &rez)
{
    while(viz[a[p].y])
        p++;
    viz[a[p].y]=1;
    if(poz>=a[p].x.x&&poz<=a[p].x.y)
        return;
    f=a[p].x.x;
    if(type==0)
        f=a[p].x.y;
    rez+=abs(f-poz);
    poz=f;
}
void rezolva(long long &rez)
{
    for(int i=1;i<=n;i++)
        viz[i]=0;
    poz=0;
    nr=n;
    p1=p2=1;
    while(nr--)
    {
       p=1-p;
       if(p==0)
        solve(b,p1,0,rez);
        else
            solve(a,p2,1,rez);
    }
    rez+=abs(poz);
}
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
    p=1;
    rezolva(rez);
    p=0;
    rezolva(rez2);
    cout<<max(rez2,rez);
}
