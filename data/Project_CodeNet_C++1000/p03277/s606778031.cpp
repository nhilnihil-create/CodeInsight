//#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,a[200010],sum[200010];
struct node{
    int l,r,sum;
}t[1600080];
void build(int k,int l,int r){
    t[k].l=l;
    t[k].r=r;
    if(l==r){
        t[k].sum=0;
        return ;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    t[k].sum=t[k*2].sum+t[k*2+1].sum;
}
void change(int k,int x){
    if(x==t[k].l&&x==t[k].r){
        t[k].sum++;
        return ;
    }
    int mid=(t[k].l+t[k].r)/2;
    if(x<=mid)
        change(k*2,x);
    else
        change(k*2+1,x);
    t[k].sum=t[k*2].sum+t[k*2+1].sum;
}
int ask(int k,int l,int r){
    if(l>r)
		return 0;
    if(l<=t[k].l&&t[k].r<=r) 
		return t[k].sum;
    int mid=(t[k].l+t[k].r)/2;
    if(r<=mid)
        return ask(k*2,l,r);
    if(l>mid)
        return ask(k*2+1,l,r);
    return ask(k*2,l,mid)+ask(k*2+1,mid+1,r);
}
int check(int x){
    long long ans=0;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+((a[i]<=x)?1:-1);
    for(int i=0;i<=n;i++)
        sum[i]+=n+1;
    build(1,1,200010);
    for(int i=0;i<=n;i++){
        ans+=ask(1,1,sum[i]-1);
        change(1,sum[i]);
    }
    return ans>=1ll*n*(n+1)/4+1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=1,r=1e9,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
        if(r-l<=1){
        	mid=check(l)?l:r;
            break;
        }
    }
    cout<<mid;
    return 0;
}