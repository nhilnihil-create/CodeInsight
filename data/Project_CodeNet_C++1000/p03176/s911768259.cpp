#include<bits/stdc++.h>
using namespace std;
#define int long long

string s;
int mo=1000000007; 
struct  stnode
{
    int ma; 
};
stnode st[1000005];

int h[200005];
int bty[200005];
int n;
void merge(stnode &f,stnode &n1,stnode &n2)
{
   f.ma=max(n1.ma,n2.ma);
}
void build(int node ,int l ,int r)
{
    if(l==r)
    {
        st[node].ma=0;
        return ; 
    }
    int m=(l+r)/2;
    build(2*node , l, m);
    build(2*node + 1, m+1 ,r);
    merge(st[node],st[2*node],st[2*node +1]);
 
}
  
void update(int node,int l,int r,int pos,int val)
{
    if(l==r)
    {
        st[node].ma=max(st[node].ma,val);
    }
    else
    {
        int mid=(l+r)/2;
        if(pos<=mid)
            update(2*node , l ,mid,pos,val);
        else
            update(2*node +1 , mid +1 ,r,pos,val);
        merge(st[node],st[2*node],st[2*node + 1]);
        //cout<<ind<<" "<<st[ind].best<<"\n";
    }
}
 
stnode query(int ind, int l, int r, int lo, int hi)
{
    if(l==lo && r==hi)
        return st[ind];
    int mid =(l+r)/2;
    if(lo > mid)
        return query(2*ind + 1,mid +1,r,lo,hi);
    if(hi<=mid)
        return query(2*ind,l,mid,lo,hi);
    stnode left = query(2*ind, l, mid,lo,mid);
    stnode right = query(2*ind +1, mid +1,r,mid + 1,hi);
    stnode result ;
    merge(result,left,right);
    return result;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    build(1,1,n);
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
        cin>>bty[i];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int q=0;
        if(h[i]>1)
            q=query(1,1,n,1,h[i]-1).ma;
        ans=max(ans,q+bty[i]);
        update(1,1,n,h[i],q+bty[i]);
    }
    cout<<ans;
}
