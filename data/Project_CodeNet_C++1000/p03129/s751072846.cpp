#include<bits/stdc++.h>
#define int long long
using namespace std;


int mm[500005];
int ind[500005];
int seg[2000005];
void upd(int ver,int tl,int tr,int pos,int val)
{
    if(tl>tr)
        return ;
    else if(tl==tr)
    {
        seg[ver]=val;
    }
    else
    {
        int tm=(tl+tr)/2;
        if(tm>=pos)
        upd(2*ver,tl,tm,pos,val);
        else
            upd(2*ver+1,tm+1,tr,pos,val);
        seg[ver]=seg[2*ver]+seg[2*ver+1];
    }    
}

int get(int ver,int tl,int tr,int l,int r)
{
    if(tl>tr||l>r||tr<l||r<tl)
        return 0;
    else if(tl==l&&tr==r)
        return seg[ver];
    else
    {
        int tm=(tl+tr)/2;
        return get(2*ver,tl,tm,l,min(tm,r))+get(2*ver+1,tm+1,tr,max(tm+1,l),r);
    }    
}
int ans[500005];

signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif      

    int n,k;
    cin>>n>>k;
    int z=(n+1)/2;
    if(z>=k)
        cout<<"YES";
    else    
    cout<<"NO";

}