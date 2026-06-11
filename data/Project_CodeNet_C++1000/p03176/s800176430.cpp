#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <functional> // for less 
// #include <iostream> 
// using namespace __gnu_pbds; 
using namespace std;
#define int  long long int
#define mod 1000000000000007
#define pb push_back
#define mp make_pair
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define gcd __gcd
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define all(i) i.begin(),i.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define set_bit __builtin_popcount //gives number of set_bits
#define ff first
#define ss second
#define cases(t) int t;cin>>t; rep(casn,1,t+1)
#define el cout<<"\n";
#define deci(n) int n; scanf("%lld",&n);
#define decs(n) string n; cin>>n;
#define sz(v) v.size()
#define repit(m) for(auto it=m.begin();it!=m.end();it++)
// #define find(m,i) (m.find(i)!=m.end())
// #define find(m,i) (m.find(i)==m.end())
#define cYES cout<<"YES\n";
#define cNO cout<<"NO\n";
#define ins insert
#define imax 1000000000000000000
#define imin -1000000000000000000
// typedef tree<int, null_type, less<int>, rb_tree_tag, 
//              tree_order_statistics_node_update> 
//     new_data_set;
// #define NP 50000
//  cerr << "\nTime : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
 
//  IIITA
//SUNEET KUMAR -->  ਸੁਨੀਤ
 
// scanning numbers extremely fast/////////
void fs(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
// ========================================
int power(int a,int x)
{
        a%=mod;
    int res=1;
    while(x>0)
    {
        if(x&1)
        res=res*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return res;
}
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int min(int a,int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int madd(int a,int b)
{
    int ans;
    ans=(a%mod+b%mod)%mod;
    return ans;
}
int mmult(int a,int b)
{
    int ans=1;
    ans=((a%mod)*(b%mod))%mod;
    return ans%mod;
}
int modinverse(int a)
{
    return power(a,mod-2);
}
int tree[800005],dph[200005];
void build(int node,int start,int end)
{
    if(start==end)
    {
        tree[node]=dph[start];
    }
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
}
int query(int node,int start,int end,int l,int r)
{
    if(start>=l&&end<=r)
    {
        return tree[node];
    }
    else if(start>r||end<l)
    {
        return 0;
    }
    else
    {
        int mid=(start+end)/2;
        return max(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
    }
}

void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
        dph[idx]=val;
        tree[node]=max(val,tree[node]);
    }
    else
    {
        int mid=(start+end)/2;
        if(start<=idx&&mid>=idx)
        {
            update(2*node,start,mid,idx,val);
        }
        else
        {
            update(2*node+1,mid+1,end,idx,val);
        }
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
}

void its_her_choice()
{
    int n;cin>>n;
    int h[n+4],a[n+4];
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    // int dph[n+4];
    for(int i=0;i<=n;i++)
    {
        dph[i]=0;
    }
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        int prev=query(1,1,n,1,h[i]-1);
        // for(int j=h[i]-1;j>0;j--)
        // {
        //     if(dph[j]>0)
        //     {
        //         prev=max(prev,dph[j]);
        //         // break;
        //     }
        // }
        update(1,1,n,h[i],a[i]+prev);
        // dph[h[i]]=a[i]+prev;
    }
    int mx=-1;
    for(int i=1;i<=n;i++)
    {
        mx=max(dph[i],mx);
    }
    cout<<mx;el

}
signed main()
{   
     its_her_choice(); 
}