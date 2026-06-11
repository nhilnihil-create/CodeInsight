#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define pb push_back
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define clr(v) v.clear()
vector<ll>v;
pair<ll,ll>p;
map<ll,ll>mp;
set<ll>st;
deque<ll>dq;
priority_queue<ll>pq;
#define f(i,b) for(i=0;i<b;i++)
#define f1(i,b) for(i=1;i<=b;i++)
#define fr(i,b)for(i=b-1;i>=0;i--)
ll mn=INT_MAX,mx=INT_MIN;
ll n,m,tc,i,j,tmp,sum,cn,ans,res,pos,flag;

string s;


ll a[200007],b[200007];
int main()
{

   io;
string str;

cin>>s>>str;
ll l=s.size();
if(l!=str.size())
{
    puts("No");
}
else
{
 for(i=0;i<l;i++)
 {
     bool flag=true;
     for(j=0;j<l;j++)
     {
         if(s[j]!=str[(j+i)%l])
            {flag=false;}

     }
     if(flag==true)
     {
         puts("Yes");
         return 0;
     }
 }
 puts("No");
}
return 0;
}



