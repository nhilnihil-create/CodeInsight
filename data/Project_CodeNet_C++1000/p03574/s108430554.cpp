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
             if(arr[i][j]=='.')
             {
                 ll cnt;
                 cnt=(arr[i-1][j-1]=='#')+(arr[i-1][j]=='#')+(arr[i-1][j+1]=='#')+(arr[i][j-1]=='#')+(arr[i][j+1]=='#')+(arr[i+1][j-1]=='#')+(arr[i+1][j]=='#')+(arr[i+1][j+1]=='#');
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
