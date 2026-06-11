//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200005
#define MOD 1000000007
ll mx[4*MAXN];

class segTree
{
    public:
    
    void update(ll i,ll v,ll x,ll lx,ll rx)
    {
        if(lx == rx)
        {
            mx[x] = v;
            return;
        }
        
        ll mid = (lx + rx)/2;
        
        if(i <= mid)
            update(i,v,2*x + 1,lx,mid);
        else
            update(i,v,2*x + 2,mid + 1,rx);
        
        mx[x] = max(mx[2*x + 1],mx[2*x + 2]);
    }
    
    void update(ll i,ll v,ll N)
    {
        update(i,v,0,0,N - 1);
    }
    
    ll query(ll L,ll R,ll x,ll lx,ll rx)
    {
        if(rx < L || lx > R)
            return(0);
        
        if(lx >= L && rx <= R)
            return(mx[x]);
        
        ll mid = (lx + rx)/2;
        ll left = query(L,R,2*x + 1,lx,mid);
        ll right = query(L,R,2*x + 2,mid + 1,rx);
        
        return(max(left,right));
    }
    
    ll query(ll L,ll R,ll N)
    {
        return(query(L,R,0,0,N - 1));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    ll H[N],B[N];
    
    for(ll i=0;i<N;++i)
    {
        cin>>H[i]; 
        H[i]--;
    }
    
    for(ll i=0;i<N;++i)
        cin>>B[i];
    
    segTree st;
    
    for(ll i=0;i<N;++i)
    {
        ll val = st.query(0,H[i],N);
        st.update(H[i],val + B[i],N);
    }
    cout<<st.query(0,N - 1,N)<<endl;
}