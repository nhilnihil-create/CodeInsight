#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a=0,b=0;
    for(int i=1;i<=n;i++)if(i%k==0)a++;
   if(k%2==0) for(int i=1;i<=n;i++)if(i%k==k/2)b++;
    long long ans=pow(a,3)+pow(b,3);
    cout<<ans<<endl;
}
