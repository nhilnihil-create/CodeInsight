///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100009;

int a[55],n,k;
int chk(int i,int j)
{
    int lft=i-1;
    int rgt=n-j;
    if(lft+rgt>k)return -1;
    priority_queue<int>pq;
    int sum=0;
    for(int p=1;p<i;p++)pq.push(-a[p]),sum+=a[p];
    for(int p=j+1;p<=n;p++)pq.push(-a[p]),sum+=a[p];
    int baki=k-(lft+rgt);
   // cout<<sum<<" sum & baki "<<baki<<endl;
    while(baki>=1 && !pq.empty())
    {
         int x=-pq.top();
         pq.pop();
         //cout<<x<<" popping "<<endl;
         baki--;
         if(x<0)
         {
             sum-=x;
         }
         else
         {
             break;
         }
    }
    return sum;
}
int corner()
{
   if(k<n)return -1;
   int sum=0;
   f(i,1,n)
   {
       if(a[i]>0)sum+=a[i];
   }
   return sum;
}
 main()

{
    fast
    cin>>n>>k;
    int ses=0,tot=0;
    f(i,1,n)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            ses=max(ses,chk(i,j));
        }
    }
    //cout<<chk(3,5)<<"######"<<endl;
    ses=max(ses,corner());
    cout<<ses<<endl;
    return 0;

}



































