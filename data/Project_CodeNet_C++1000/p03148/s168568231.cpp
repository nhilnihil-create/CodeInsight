#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <math.h>
#include <set>
#include <map>
#include <stdio.h>
#include <queue>
#include <iomanip>
#include <cstring>
#include <stack>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ff first
#define ss second
using namespace std;
typedef long long ll;
using namespace std ;
struct node
{
    ll x,y;
    bool operator<(const node&o)const
    {
        return y>o.y;
    }
}a[100005];
ll n,k,cot=0;
bool vis[100005];

stack<ll>s;
int main()
{
    long long ans=0,res=0,type=0;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
       cin>>a[i].x>>a[i].y ;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(cot<k)
        {
            if(!vis[a[i].x])
            {
                vis[a[i].x]=true;
                type++;
            }
            else s.push(a[i].y);
            res+=a[i].y;
            cot++;
            ans=max(ans,res+type*type);
        }
        else
        {
            if(s.empty())break;
            if(vis[a[i].x]) continue;
            vis[a[i].x]=true;
            type++;
            res+=a[i].y;
            res-=s.top();s.pop();
            ans=max(ans,res+type*type);
        }
    }
    cout<<ans<<endl;
}

