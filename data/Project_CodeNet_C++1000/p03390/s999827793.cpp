#include<bits/stdc++.h>
#define pi 3.141592653897932384626
//freopen("std.in","r",stdin);freopen("std.out","w",stdout);
using namespace std;
int main()
{
    long long n,a,b,sum,x,y;
    cin>>n;
    for(long i=0;i<n;i++){
        scanf("%lld%lld",&a,&b);
        x=min(a,b);
        y=sqrt(a*b);
        if(a==b){cout<<(a-1)*2<<endl;continue;}
        sum=(y-1)<<1;
        if(y*y==a*b)sum--;
        if(y*(y+1)<a*b)sum++;
        cout<<sum<<endl;
    }
    return 0;
}
