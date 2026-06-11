#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
ll dx[8]={-1,-1,-1,0,0,1,1,1};
ll dy[8]={-1,0,1,-1,1,-1,0,1};
int main()
{
     ll r,c;
     char arr[55][55];
     cin>>r>>c;
     for(int i=0;i<=r+1;i++)
     {
         for(int j=0;j<=c+1;j++)
         {
             arr[i][j]='.';
         }
     }
     for(int i=1;i<=r;i++)
     {
         for(int j=1;j<=c;j++)
         {
             cin>>arr[i][j];
         }
     }
     for(int i=1;i<=r;i++)
     {
         for(int j=1;j<=c;j++)
         {
             ll  cnt=0;
             if(arr[i][j]=='.')
             {
                 for(int k=0;k<8;k++)
                 {
                     ll x=dx[k]+i;
                     ll y=dy[k]+j;
                     if(arr[x][y]=='#')
                        cnt++;
                 }
                 arr[i][j]=cnt+48;
             }
         }
     }
     for(int i=1;i<=r;i++)
     {
         for(int j=1;j<=c;j++)
         {
             cout<<arr[i][j];
         }
         cout<<endl;
     }
}
