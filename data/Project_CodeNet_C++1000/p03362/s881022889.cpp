#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

bool prime[N];

void seive()
{
    memset(prime,true,sizeof prime);

   for(int i=2;i*i<=N;i++)
   {
       if(prime[i]==true)
       {
           for(int j=i*2;j<=N;j+=i)prime[j]=false;
       }
   }

}
int main()
{
    seive();
    int n;
    cin>>n;

   for(int i=31;i<=55555;i+=30)
   {
       if(prime[i])
       {
           cout<<i<<" ";
           n--;
       }
       if(n==0)break;
   }
}
