#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
const int MAXN=205;
const ll mod = 1000000007;
const ll inf = 1e18;
typedef pair<int, int> pi;
ll gc(ll a,ll b)
{
    if(b==0) return a;
    return gc(b,a%b);
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

vector<bool>prime(100005,true);
vector<ll>v;
void sieve(ll n)
{
    prime[1]=false;
   for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(prime[i]==true)
            v.push_back(i);
    }
}

int BIT[1000];
void update(int x, int delta)
{
    int n;
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}


inline ll add(ll a,ll b) {return ((a%mod)+(b%mod))%mod;}
inline ll sub(ll a,ll b) {return ((a%mod)-(b%mod)+mod)%mod;}
inline ll mul(ll a,ll b) {return ((a%mod)*(b%mod))%mod;}


ll recur(ll idx,ll sum, vector<pair<ll,ll> >& v, vector<ll>& b, vector<ll>& pre, vector<ll>& dp)
{
    if(idx==b.size()) return 0;
    if(dp[idx]!=-1) return dp[idx];
    ll temp=INT_MAX;
    temp=min(temp,recur(idx+1,sum,v,b,pre,dp) + b[idx]);
    for(int i=0;i<v.size();i++)
    {
        ll x=v[i].first;
        ll y=v[i].second;
        if(idx+x-1>=b.size()) continue;
        ll calc= pre[idx+x-1]-pre[idx+y-1];
        temp=min(temp, recur(idx+x, sum,v,b,pre,dp)+ calc);
    }
    dp[idx]=temp;
    return temp;
}


ll find(ll u, vector<ll>& parent)
{
    if(u==parent[u]) return u;
    else return parent[u]=find(parent[u],parent);
}
 void unio(ll u, ll v, vector<ll>& parent, vector<ll>& ran)
{
    u=find(u,parent);
    v=find(v,parent);
    if(u==v) return;
    if(ran[u]>=ran[v])
    {
        parent[v]=u;
        ran[u]+=ran[v];
    }
    else{
        parent[u]=v;
        ran[v]+=ran[u];
    }
}
ll dfs(ll src, ll p, vector<ll>& a, vector<pair<ll,ll> > adj[], vector<ll>& dp)
{
    ll can1=0;
    ll can2=0;
    vector<pair<ll,ll> >:: iterator it;
    for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(((*it).first==p)) continue;
        ll st=max(0LL,dfs((*it).first,src,a,adj,dp)- (*it).second);
        if(st>can1)
        {
            can2=can1;
            can1=st;
        }
        else if(st>can2)
        {
            can2=st;
        }
    }
    dp[src]=a[src]+ can1+can2;
    return (max(can1,can2)+ a[src]);
}

struct comp1{
    bool operator ()(pair<ll,ll>& temp1, pair<ll,ll>& temp2)
{

}
};
bool comp2(pair<ll,ll>& temp1, pair<ll,ll>& temp2)
{
    return temp1.second<temp2.second;
}


int main() {
ll n,m;
cin>>n>>m;
vector<ll>parent(n+1);
vector<ll>sz(n+1);
for(int i=1;i<=n;i++)
{
    parent[i]=i;
    sz[i]=1;
}
vector<pair<ll,ll> >v;
for(int i=0;i<m;i++)
{
    ll u1,u2;
    cin>>u1>>u2;
    v.pb(mp(u1,u2));
}
reverse(v.begin(),v.end());
vector<ll>ans(m);
ans[0]=0;
for(ll i=1;i<m;i++)
{
    ll nod1=v[i-1].first;
    ll nod2=v[i-1].second;
    ll p1=find(nod1,parent);
    ll p2=find(nod2,parent);
    if(p1==p2)
        ans[i]=ans[i-1];
    else
    {
        ans[i]=sz[p1]*sz[p2];
        //cout<<p1<<" "<<p2<<" "<<sz[p1]<<" "<<sz[p2]<<" "<<i<<" "<<ans[i]<<endl;
       // cout<<p1<<" "<<sz[p1]<<" "<<p2<<" "<<sz[p2]<<endl;
        unio(nod1,nod2,parent,sz);
        if(i!=0) ans[i]+=ans[i-1];
        //cout<<p1<<" "<<sz[p1]<<" "<<p2<<" "<<sz[p2]<<endl;
    }
}
for(int i=m-1;i>=0;i--)
{
    ll ret=(((n*(n-1)))/2  -ans[i]);
    cout<<ret<<endl;
}

}
