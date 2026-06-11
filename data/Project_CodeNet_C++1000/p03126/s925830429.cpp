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
     ll n,m,arr[1000],cnt=0;
     mem(arr,0);
     cin>>n>>m;
     for(int i=0;i<n;i++)
     {
         ll kk,v;
         cin>>kk;
         for(int i=0;i<kk;i++)
         {
             cin>>v;
             arr[v]++;
         }
     }
     for(int i=1;i<=m;i++)
     {
         if(arr[i]==n)
            cnt++;
     }
     cout<<cnt<<endl;
}


