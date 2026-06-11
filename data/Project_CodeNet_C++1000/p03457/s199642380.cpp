#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*
ll dx[8]={-1,-1,-1,0,0,1,1,1};
ll dy[8]={-1,0,1,-1,1,-1,0,1};
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
*/
int main()
{
     ll n,t=0,x=0,y=0,t1,cnt=0,a,b;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         cin>>t1>>a>>b;
         ll diff=abs(a-x)+abs(b-y);
         t=t1-t;
         if(diff>t)
         cnt=10;
         if((t-diff)%2)
         cnt=10;
         x=a,y=b,t=t1;
     }
     if(cnt==10)
        cout<<"No"<<endl;
     else
        cout<<"Yes"<<endl;
}
