#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>
#define PII pair<ll, ll>
#define llu long long unsigned
#define ld long double

const ll MAX = 1e18 + 100;
const ll Max = 1e9 + 500;

const int sz=2e5+100;
int sum[22];
int ara[sz];
void ADD(int id,int val)
{
   for(int i=0;i<20;i++){
      if((ara[id] & (1<<i)) != 0) sum[i]+=val;
   }

}

bool check()
{
    for(int i=0;i<20;i++){
       if(sum[i]>1) return false;
    }
    return true;
}


int main()
{
   int t, i, j, k, p, q, a, b, c, mx,n,x;
   
   cin>>n;
   for(i=0;i<n;i++) cin>>ara[i];

   ll ans=0;
   i=0, j=0;

   while(i<n){
       
       ADD(i,+1);
       while(j<i && check()==false){
          ADD(j,-1);
          ++j;
       }

       ll p=(i-j+1);
       ans+=p;
       ++i;
   }

   cout<<ans<<'\n';
   
}