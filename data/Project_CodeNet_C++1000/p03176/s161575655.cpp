#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 200100;

int n;
vector <ll> a,h,pos;
ll ans;

struct segtree
{
    int sz;

    vector <ll> maxs;

    void init(int n)
    {
        sz = n;
        maxs.resize(n<<2);
    }

    void update(int nd,int l,int r,int pos,ll val)
    {
        if( l == pos && r == pos )
        {
            maxs[nd] = val;
            return;
        }

        int mid = (l+r)/2;

        if( pos <= mid )
            update(nd<<1,l,mid,pos,val);
        else
            update(nd<<1|1,mid+1,r,pos,val);

        maxs[nd] = max( maxs[nd<<1] , maxs[nd<<1|1] );
    }

    void update(int pos,ll val) { update(1,1,sz,pos,val); }

    ll querymax(int nd,int l,int r,int from,int to)
    {
        if( from <= l && r <= to )
            return maxs[nd];
        if( from > r || l > to )
            return 0;

        int mid = (l+r)/2;

        return max( querymax(nd<<1,l,mid,from,to) , querymax(nd<<1|1,mid+1,r,from,to) );
    }

    ll querymax(int l,int r) { return querymax(1,1,sz,l,r); }
};

int main()
{
    scanf("%d",&n);
    h.resize(n+10);
    a.resize(n+10);
    pos.resize(n+10);

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&h[i]);
        pos[h[i]] = i;
    }
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);

    segtree st;
    st.init(n);

    for(int i=n;i>=1;i--)
    {
        ll x = st.querymax(pos[i],n);

        ans = max( ans , x+a[pos[i]] );

        st.update(pos[i],x+a[pos[i]]);
    }

    printf("%lld\n",ans);
}
