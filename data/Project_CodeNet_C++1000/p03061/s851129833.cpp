#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int max=INT_MIN;
  cin>>n;
int arr[n],pre[n],suf[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];

}
int x=arr[0];
for(int i=0;i<n;i++)
{
    x=__gcd(arr[i],x);
pre[i]=x;


}

x=arr[n-1];
for(int i=n-1;i>=0;i--)
{
x=__gcd(arr[i],x);
suf[i]=x;

}

for(int i=0;i<n-2;i++)
{
   
    if(__gcd(suf[i+2],pre[i])>max)
    {
       
        max=__gcd(suf[i+2],pre[i]);
    }
}
if(suf[1]>max)
max=suf[1];
if(suf[0]>max)
max=suf[0];
if(pre[n-1]>max)
max=pre[n-1];
if(pre[n-2]>max)
max=pre[n-2];
cout<<max;
}
