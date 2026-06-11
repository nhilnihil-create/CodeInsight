#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n,m,d;
    cin>>n>>m>>d;
    double ans=0;
    ans=(m-1)*(2*(n-d))/(n*n);
    ans-=((!d)*ans/2);
    printf("%.9f",ans);
}
