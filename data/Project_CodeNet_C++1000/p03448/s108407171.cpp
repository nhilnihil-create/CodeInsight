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
     ll t,a,b,c,d,cnt=0,pk;
     cin>>a>>b>>c>>d;
     d=d/50;
     for(int i=0;i<=a;i++)
     {
         for(int j=0;j<=b;j++)
         {
             for(int k=0;k<=c;k++)
             {
                 pk=i*10+j*2+k;
                 if(pk==d)
                    cnt++;
             }
         }
     }
     cout<<cnt<<endl;
}
