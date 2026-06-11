#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        if(k>=i)continue;
        long long p=n/i;
        long long r=abs(i-k);
        p=(p*r);
        if(n%i!=0)
        {
            long long c = n-(i*(n/i));
          //  if(c==0)continue;
   //     cout<<i<<" "<<c<<endl;
          if(c>=k)p+=(c-k+1);
          if(k==0)p--;
           // else if(c==k)p+=(c-k+1);
        }
        sum+=p;
    }
    cout<<sum<<endl;
}
