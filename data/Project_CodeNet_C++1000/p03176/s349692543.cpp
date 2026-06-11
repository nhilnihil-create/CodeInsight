#include <bits/stdc++.h>      
using namespace std;            

#define    int               long long int
 #define    bp(x)         __builtin_popcount(x)
#define  ld         long double
 #define  f(i,j,n)            for(int i = j; i <= n; i++)
#define  r(i,n,j)       for(int i = n; i >= j; i--)
 #define  all(container)       container.begin() , container.end()
#define  sz(container)   (int)container.size()
 #define  ff             first
#define  ss             second
 #define  pii      pair <int , int>
#define  sp(x)       setprecision(x)
#define  mod  1000000007
#define  endl  "\n"
 #define  pb    push_back
#define  mp    make_pair
 #define  T     int ttt; cin >> ttt; while(ttt--)
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int t[800099];
int query(int node,int l,int r,int s,int e)
{
    if(l>e || r<s)   
        return 0;
    if(l<=s && e<=r)
        return t[node];
    int mid=(s+e)>>1;
    return max(query(2*node,l,r,s,mid) , query(2*node +1,l,r,mid+1,e));
}
void update(int node,int idx,int s,int e,int val)
{
    if(s==e)
        t[node]=val;
    else{
        int mid=(s+e)>>1;;
        if(s<= idx && idx<=mid)
            update(2*node,idx,s,mid,val);
        else
            update(2*node +1,idx,mid+1,e,val);
        t[node]=max(t[2*node] , t[2*node +1]);
    }
}


int32_t main()
{
    fast
    int n,ans=0;  cin>>n;
    int a[n+1],h[n+1];
    f(i,1,n)    cin>>h[i];
    f(i,1,n)    cin>>a[i];
    update(1,h[1],1,n,a[1]);
    ans=a[1];
    f(i,2,n){
        int x=query(1,1,h[i],1,n);
        update(1,h[i],1,n,a[i]+x);
        ans=max(ans,x+a[i]);
    }
    cout<<ans;
}