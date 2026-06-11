#include <bits/stdc++.h>
using namespace std;
int arr[101][2],n,m,i,j,maxx=0;
int main ()
{
cin>>n;
for (i=1;i<=n;i++) cin>>arr[i][0];
for (i=1;i<=n;i++) cin>>arr[i][1];
for (i=1;i<=n;i++)
{
int sum=0;
for (j=1;j<=i;j++) sum+=arr[j][0];
for (j=i;j<=n;j++) sum+=arr[j][1];
if (maxx<sum) maxx=sum;
}
cout<<maxx;
}