#include<bits/stdc++.h>

#define inp 200005
#define check exit(0)
#define nl cout<<endl;
#define mod 1000000007 
#define ll long long int
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(v) for(int i=0;i<v.size();i++) {cout<<v[i]; (i==v.size()-1) ? cout<<"\n":cout<<" "; }

using namespace std;

// Pick yourself up, 'cause...

vector<ll> v(inp),h(inp);
vector<ll> st(inp<<2,0);

int n;

void update(int i,ll nwans,int si=1,int ss=1,int se=n)
{
    if(ss==se) { st[si]=max(st[si],nwans); return; }
    int mid=(ss+se)/2;
    if(i<=mid) update(i,nwans,si*2,ss,mid);
    else update(i,nwans,si*2+1,mid+1,se);
    st[si]=max(st[2*si],st[2*si+1]);
}

int ch;
ll query(int l=1,int r=ch,int si=1,int ss=1,int se=n)
{
    if(ss>r || se<l) return 0;
    if(ss>=l && se<=r) return st[si];
    int mid=(ss+se)/2;
    return max(query(l,r,si*2,ss,mid),query(l,r,si*2+1,mid+1,se));
}

int main()
{
    jaldi

    cin>>n;

    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>v[i];

    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ch=h[i];
        ll cv=v[i];

        ll maxans = cv+query();
        ans=max(ans,maxans);
        update(ch,maxans);
        //trace(maxans);
    }
   
    cout<<ans;
    
    return 0;
}