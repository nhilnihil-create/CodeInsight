#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(NULL); cin.tie(NULL);

using namespace std;
const int N = 1E6+7;
const long long INF = 1E18;

long long NODE[N];
long long a[N], h[N];
int n;

long long get_max(int id,int s,int e,int l,int r)
{
    if (s > e || l > e || r < s) return -INF;
    
    if (l <= s && e <= r) return NODE[id];
    
    int mid = (s+e)>>1;
    long long tmp1 = get_max(id*2,s,mid,l,r);
    long long tmp2 = get_max(id*2+1,mid+1,e,l,r);
return max(tmp1,tmp2);
}

void update(int id,int s,int e,int pos,long long val)
{
    if (s > e || pos < s || pos > e) return;
    
    if (s == e)
    {
        if (s == pos)
        {
            NODE[id] = val;
            return;
        }
        return;
    }
    
    int mid = (s+e)>>1;
    update(id*2,s,mid,pos,val);
    update(id*2+1,mid+1,e,pos,val);
    NODE[id] = max(NODE[id*2],NODE[id*2+1]);
}

int main()
{
    fastIO
    cin>>n;
    
    for (int i = 1;i <= n;++i) cin>>a[i];
    
    for (int i = 1;i <= n;++i) cin>>h[i];
    
    long long res = 0;
    for (int i = 1;i <= n;++i)
    {
        long long k = get_max(1,1,n,1,a[i]) + h[i];
        update(1,1,n,a[i],k);
        res = max(res,k);
    }
    
    cout<<res;
}