#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 2e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

int A[MAXN];
int B[MAXN];
int tree[MAXN*4];
vector<int> val;

void update(int tmp,int v)
{
    tree[tmp]+=v;
    tmp>>=1;

    while(tmp){
        tree[tmp] = tree[tmp<<1]+tree[((tmp<<1)|1)];
        tmp>>=1;
    }

    return;
}

int getans(int L,int R)
{
    int res = 0;

    while(L<=R){
        if(L&1){res+=tree[L]; L++;}
        if(!(R&1)){res+=tree[R]; R--;}
        L>>=1; R>>=1;
    }

    return res;
}

bool ok(int x,int n)
{
    for(int i=1;i<=n;i++){
        if(A[i]>=x)B[i] = 1;
        else B[i] = -1;
    }

    for(int i=1;i<=n;i++)
        B[i]+=B[i-1];

    vector<int> tmp;

    for(int i=0;i<=n;i++)
        tmp.push_back(B[i]);

    sort(tmp.begin(),tmp.end());

    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

    int base = 1;
    int tsz = tmp.size();
    int idx;

    for(;base<tsz;base<<=1);

    for(int i=1;i<(base<<1);i++)tree[i] = 0;

    ll res = 0;

    for(int i=0;i<=n;i++){
        idx = lower_bound(tmp.begin(),tmp.end(),B[i])-tmp.begin();
        res+=(ll)getans(base,base+idx);
        update(base+idx,1);
    }
    return (2*res>=(1LL*n*(n+1)/2));
}

int main()
{
    int n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        val.push_back(A[i]);
    }

    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());

    for(int i=1;i<=n;i++){
        idx = lower_bound(val.begin(),val.end(),A[i])-val.begin();
        A[i] = idx;
    }

    int sz = val.size();

    int L = 0;
    int R = sz-1;
    int mid,ans = 0;

    while(L<=R){
        mid = (L+R)>>1;
        if(ok(mid,n))ans = mid,L = mid+1;
        else R = mid-1;
    }

    cout<<val[ans]<<"\n";

    return 0;
}
