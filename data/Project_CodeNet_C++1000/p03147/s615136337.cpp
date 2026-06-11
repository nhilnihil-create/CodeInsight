/****************************************************************************************************
                                        SUBMITTED BY-

                                                AISH_07

****************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define sl set<ll>
#define vs vector<string>
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define PI  3.14159265
#define mod 998244353
void solve(int a[],int st,int anth)
{
    for(int i=st;i<anth;i++)
    {
        if(a[i]==0)
            return ;
        a[i]--;
    }
    return ;
}
int dh_zero(int a[],int st,int anth)
{
    for(int i=st;i<anth;i++)
    {
        if(a[i]!=0)
            return i;
    }
    return anth;
}
int main()
{
   int n;
   cin>>n;

   int a[n];

   for(int i=0;i<n;i++)
    cin>>a[i];

   int ans=0;
   int shuru=0;

   while(1)
   {
       shuru=dh_zero(a,shuru,n);
       if(shuru==n)
        break;
       ans++;
       solve(a,shuru,n);
   }
   cout<<ans<<"\n";
    return 0;
}
