#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define PI acos(-1.0)
typedef long long ll;
const int INF=0x3f3f3f3f;
//const ll INF=1000000000000000000;
 
//priority_queue<int, vector<int>, greater<int> >p;
int s[500005];
int main()
{
    ll n,a,b;
    scanf("%lld%lld%lld",&n,&a,&b);
    ll sum=n-a;
    if(a+b-1>n||a*b<n)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
        s[i]=i;
    for(int i=n;i>0;i-=b)
    {
        int t=b-1;
        if(sum<=t)
        {
            t=sum;
            for(int j=i;j>i-sum-1;j--)
            {
                s[j]=i-t;
                t--;
            }
            break;
        }
        sum-=t;
        for(int j=i;j>i-b;j--)
        {
            s[j]=i-t;
            t--;
        }
    }
    printf("%d",s[1]);
    for(int i=2;i<=n;i++)
        printf(" %d",s[i]);
    printf("\n");
    return 0;
}
 