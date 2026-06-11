//AUTHOR: RAVAN_2070
//PUNE INSTITUTE OF COMPUTER TECHNOLOGY
//Atcoder Educational DP
//N-Slimes
/*
    I ♥ CLARICE STARLING

    EXPLAINATION BELOW->
    Dp+segment tree

*/
//Iterative Solution
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(x) x.begin(),x.end()
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define MOD7 1000000007
const ll INF=(ll)1e18+5;
const int N=(int)2e5+5;
int n;
ll a[N],h[N];
ll dp[N],segment_tree[2*N+1];
/*void update(int node,int start,int end,int idx,ll val)
{
    if(start==end)segment_tree[node]=max(segment_tree[node],val);
    else
    {
        int mid=start+(end-start)/2;
        if(start>=idx&&idx<=mid)update(2*node,start,mid,idx,val);
        else update(2*node+1,mid+1,end,idx,val);
        
        segment_tree[node]=max(segment_tree[2*node],segment_tree[2*node+1]);
    }
}*/
void update(int node,int st,int en,int id,long long val)
{
    if(st>en || st>id || en<id) return ;
    if(st==en && st==id){
        segment_tree[node]=max(segment_tree[node],val);
        return ;
    }
    int mid=(st+en)/2;
    if(st<=id && id<=mid){
        update(2*node,st,mid,id,val);
    }
    else{
        update(2*node+1,mid+1,en,id,val);
    }	
    segment_tree[node]=max(segment_tree[2*node],segment_tree[2*node+1]);
}
ll query(int node,int start,int end,int l,int r)
{
    if(start>r||end<l)return 0;
    if(start>=l&&end<=r)return segment_tree[node];
    int mid=start+(end-start)/2;
    return max(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}
//dp[i] indicates max possible sum when i is the last height considered 
void solve()
{
    int i;cin>>n;
    foe(i,1,n)cin>>h[i];
    foe(i,1,n)cin>>a[i];
    dp[0]=0;
    
    ll ans=0;
    foe(i,1,n)
    {
       ll tmp=query(1,1,n,1,h[i]-1);
        dp[h[i]]=a[i]+tmp;
        update(1,1,n,h[i],dp[h[i]]);
    }
    
    foe(i,0,n)ans=max(ans,dp[i]);
    cout<<ans<<"\n";

}
int main()
{
   fastio
   solve();
  return 0;
}

