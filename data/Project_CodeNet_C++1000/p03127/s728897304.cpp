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
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
  ll ans=a[0];
  for(int i=1;i<n;i++)
  {
      ans=(__gcd(a[i],ans));

  }
  cout<<ans<<endl;


}
