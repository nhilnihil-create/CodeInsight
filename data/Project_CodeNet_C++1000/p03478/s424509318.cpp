#include<bits/stdc++.h>
#define ll long long
#define mod 838627288460106
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll n,a,b,i,j,sum=0,tmp;
    cin>>n>>a>>b;
   for(i=1;i<=n;i++)
   {
       ll x=0;
       tmp=i;
       while(tmp>0)
       {
            x+=tmp%10;
           tmp/=10;
       }
       if(x>=a&&x<=b)
        sum+=i;

   }
   cout<<sum<<endl;

    return 0;
}



