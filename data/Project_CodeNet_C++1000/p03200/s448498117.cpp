#define ll long long
#define pi acos(-1.0)
#define Go "\n"
#define Afor(i,a,b) for( i=a;i<b;i++)
#define GCD __gcd
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll i,j,sum=0;
   string s;
   cin>>s;
   ll len=s.size();
   for(i=0,j=1;i<len;i++)
   {
       if(s[i]=='W')
       {
           sum=sum+(i+1)-j;
           j++;
       }
   }
   cout<<sum<<"\n";


}
