#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int h,w,k;
    cin>>h>>w>>k;
    int x[h*w+1],y[h*w+1];
    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
    {
        int ch;
        cin>>ch;
        x[ch]=i;
        y[ch]=j;
    } 
    int d[h*w+1];
    memset(d,0,sizeof(d));
    for(int i=k+1;i<=h*w;i++)
    d[i]=d[i-k]+abs(x[i]-x[i-k])+abs(y[i]-y[i-k]);

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<d[r]-d[l]<<endl;
    }

}