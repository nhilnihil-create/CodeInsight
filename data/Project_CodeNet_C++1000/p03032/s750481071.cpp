#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll>pa;

const int N=2e5+100;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int n,k;
priority_queue<int,vector<int>,greater<int>>q;
int  head[100],to[100];
int a[100];
int ans=0;
void work(int l,int r)
{
    int kk=k-l-r;
    int sum=0;
    while(q.size()) q.pop();
    for(int i=1;i<=l;i++){
        q.push(a[i]);
    }
    for(int i=n;i>=n-r+1&&i>l;i--){
        q.push(a[i]);
    }
    int ll=n-r+1;
    if(ll<=l)
        sum=head[n];
    else
    sum=head[l]+to[ll];
   // cout<<sum<<endl;
    while(q.size()&&kk--){
        int p=q.top();
        if(p>0) break;
        else {
            q.pop();
            sum-=p;
        }
    }
   // cout<<sum<<"**"<<endl;
    ans=max(sum,ans);
}
int main()
{
   ios::sync_with_stdio(0);cin.tie(0);
   cin>>n>>k;
   for(int i=1;i<=n;i++){
     cin>>a[i];
   }
   for(int i=1;i<=n;i++){
     head[i]=head[i-1]+a[i];
   }
   for(int i=n;i>=1;i--){
     to[i]=to[i+1]+a[i];
   }
   for(int i=0;i<=n;i++)
     if(i<=k){
      for(int j=0;j+i<=k;j++){
          work(i,j);
       }
     }
    cout<<ans<<endl;
   return 0;
}

