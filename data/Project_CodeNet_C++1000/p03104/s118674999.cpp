#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
ll f(ll x)//f(0,x)的异或和
{
   if(x%4==0)
   {
       return x;
   }
   if(x%4==1)
   {
       return 1;
   }
   if(x%4==2)
   {
       return x+1;
   }
   if(x%4==3)
   {
       return 0;
   }
}
int main()
{
    ll a,b;
    cin>>a>>b;
    ll ans=f(a-1)^f(b);
    cout<<ans<<endl;
    return 0;
}
