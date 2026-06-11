#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<assert.h>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include <iomanip>
#include<bits/stdc++.h>

using namespace std;
#define lead_zero(x)    __builtin_clzll(x)
#define trail_zero(x)   __builtin_ctz(x)
#define total_1s(x)     __builtin_popcount(x)
#define ll long long int
#define pi 3.14159265358979323846
#define filein freopen("input.txt", "r", stdin)
#define forn(i,n) for(int i=0;i<n;i++)
#define maxx 1000000005
#define nullptr NULL


int main()
{
   int n;
   cin>>n;
   ll a[n+5];
   ll x=-1,ans=0,mm,mn,t=0;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];

   }
   ans=0,mm=a[0],mn=a[0];
   for(int i=1;i<n;i++)
   {
       if(a[i]<a[i-1]&&t==0)
       {
           // cout<<mn<<" "<<mm<<" "<<i<<" 1 ";
           ans+=mm;
        // cout<<ans<<endl;
           mm=0;
           mn=105;
           t=1;
       }

      else if(a[i]<a[i-1]&&t)
       {
          // cout<<mn<<" "<<mm<<" "<<i<<" 2 ";
           ans+=mm;
           ans-=mn;
           mm=0;
           mn=105;

         //  cout<<ans<<endl;


       }
       mm=max(mm,a[i]);
       mn=min(mn,a[i]);
   }
  // cout<<mn<<" "<<mm<<endl;
   if(mm!=0&&mn!=105&&t)
  {ans+=mm;
   ans-=mn;}
   else if(mm!=0&&mn!=105&&t==0)
   {
       ans+=mm;
   }
   cout<<ans<<endl;


}
