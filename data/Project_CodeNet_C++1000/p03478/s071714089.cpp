#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sum (int n )
{
    int ans =0;
    while( n>0)
    {
        ans += n%10;
        n = n/10;
    }
    return ans;
}
int main()
{
   int n , a, b;
   cin>>n>>a>>b;
   int ans =0;
   for(int i = 1;i<=n;i++)
   {
       int temp = sum( i);
       if( temp>= a&& temp <= b)
           ans += i;
   }
   cout<<ans;
}