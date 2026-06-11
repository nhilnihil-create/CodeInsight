#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(arr,v) memset(arr,v,sizeof(arr))
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
int main()
{
     double n,t,a,mn=INT_MAX,v,pk,kk,pos;
     cin>>n>>t>>a;
     for(int i=1;i<=n;i++)
     {
         cin>>v;
         kk=t-v*0.006;
         if(kk>a)
            pk=kk-a;
         else
            pk=a-kk;
         if(mn>pk)
         {
             pos=i;
             mn=pk;
         }
     }
     cout<<pos<<endl;
}

