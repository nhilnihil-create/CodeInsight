#include <bits/stdc++.h>
using namespace std;
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>

const int S = 1e4 + 10;
const int inf = 1e13 + 10;
vector<int> cur(S,0),nex(S,0);

struct dat
{
    int w,s,v;
    
    inline bool operator<(const dat & o)
    {
        return s + w < o.s + o.w;
    }
};

signed main()
{
    fast;
    
    int n;
    cin >> n;
  
    dat a[n];
    
    f(i,n) cin >> a[i].w >> a[i].s >> a[i].v;
    
    sort(a,a+n);
    
    f(i,n)
    {
        f(j,S) nex[j] = cur[j];
        
        //try to take ith element if possible
        for(int j=a[i].s;j>=0;j--)
            nex[min(j+a[i].w,S-1)] = max(nex[min(j+a[i].w,S-1)],cur[j] + a[i].v);
       
        swap(cur,nex);
    }
    
    int res = -inf;
    
    for(auto x : cur) res = max(res,x);
    
    cout << res;
}