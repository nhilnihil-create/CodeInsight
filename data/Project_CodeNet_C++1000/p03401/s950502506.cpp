#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1e5+1;
int main()
{
    int val[maxn];
    int n;
    long long cost;
    while(~scanf("%d",&n)){
        memset(val,0,sizeof(val));
        cost=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
            //cout<<'#'<<val[i]<<'#'<<endl;
            if(i==n) cost+=fabs(val[i]);
            cost+=fabs(val[i]-val[i-1]);
            //cout<<'@'<<cost<<'@'<<endl;
        }
        long long out;
        for(int i=1;i<=n;i++){
            if(i==n) out=cost-fabs(val[i])+fabs(val[i-1])-fabs(val[i]-val[i+1]);
            out=cost-fabs(val[i]-val[i-1])-fabs(val[i+1]-val[i])+fabs(val[i+1]-val[i-1]);
            printf("%lld\n",out);
        }
    }
}