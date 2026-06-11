#include <bits/stdc++.h> 
using namespace std;
const int N = 2e5 + 4;
long long tree[4*N];
long long h[N];
long long b[N];
long long dp[N];
 
void update(int node,int st,int en,int id,long long val)
{
    if(st>en || st>id || en<id) return ;
    if(st==en && st==id){
        tree[node]=max(tree[node],val);
        return ;
    }
    int mid=(st+en)/2;
    if(st<=id && id<=mid){
        update(2*node,st,mid,id,val);
    }
    else{
        update(2*node+1,mid+1,en,id,val);
    }	
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
long long query(int node,int st,int en,int l,int r)
{
    if(st>r || en<l)
        return 0;
    if(l<=st && en<=r)
        return tree[node];
 
    int mid=(st+en)/2;
    return max(query(2*node,st,mid,l,r),query(2*node+1,mid+1,en,l,r));
}
int main(){
    int n;
    cin >> n;
    int i;
    for(i=1;i<=n;i++){
        cin>>h[i];
    }
    for(i=1;i<=n;i++){
        cin >> b[i];
    }
    dp[0]=0;
    for(i=1;i<=n;i++){
        long long tmp=query(1,1,n,1,h[i]-1);
        dp[h[i]]=tmp+b[i];
        update(1,1,n,h[i],dp[h[i]]);
    }
    long long ans=0;
    for(i=0;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
 
    cout<<ans;	
	return 0;
}  
