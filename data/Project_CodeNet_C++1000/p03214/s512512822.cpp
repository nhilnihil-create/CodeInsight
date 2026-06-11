#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 0x3f3f3f3f
int n;
int a[150];
int sum;
int main()
{
    scanf("%d",&n);
    sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    double average=sum*1.0/n;
    double minn=10000;
    int minx;
    for(int i=0;i<n;i++)
    {
        if(average-a[i]<minn&&a[i]-average<minn)
        {
            minx=i;
            minn=max(average-a[i],a[i]-average);
        }
    }
    cout<<minx<<endl;
}
