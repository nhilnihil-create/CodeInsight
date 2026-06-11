#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
double mx[300],st[300],ed[300];
int t[300],v[440];
double get_s(double u,double t)
{

    double d= u*t+t*t/2;
//    cout<<"d = "<<d<<endl;
    return d;
}
double bs(int i,double mx,double tt)
{
    double l=st[i],r=mx;
    double tol=0.0000000001;
    while(l<=r)
    {
//        cout<<l<<" "<<r<<endl;
        double v=(l+r)/2;
        double t1=fabs(v-st[i]);
        double t2=fabs(v-ed[i]);
        double t3=(tt-t1-t2);

        if(t3>=0)l=v+tol;
        else r=v-tol;
    }
//    cout<<"val for "<<i<<" "<<r<<endl;
    double t1=r-st[i];
    double t2=fabs(ed[i]-r);
    double t3=tt-fabs(t1)-fabs(t2);
    double x=get_s(st[i],t1);
    double y=get_s(min(r,ed[i]),t2);
    double res=x+y+r*t3;
//    cout<<"res = "<<t1<<"  "<<x<<" "<<t2<<" "<<y<<" "<<t3<<endl;
    return res;
}
int main()
{
    cout<<setprecision(10);
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>t[i];
    for(int i=0;i<n;i++)cin>>mx[i];
//    int sum=0,ind=1;
    for(int i=n-1;i>=0;i--)
    {
        ed[i]=min(mx[i],st[i+1]);
        st[i]=min(mx[i],ed[i]+t[i]);
    }
//    for(int i=0;i<n;i++)cout<<st[i]<<" "<<ed[i]<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        if(i==0)st[i]=0;
        else st[i]=ed[i-1];
        ed[i]=min(ed[i],st[i]+t[i]);
    }
//    for(int i=0;i<n;i++)cout<<st[i]<<" "<<ed[i]<<endl;
    double ans=0;
    for(int i=0;i<n;i++)
    {
        double temp=bs(i,mx[i],t[i]);
        ans+=temp;
    }
    cout<<ans<<endl;
}
/*
2
1 2
1 2

5
6 3 3 2 3
9 8 9 2 5

*/
