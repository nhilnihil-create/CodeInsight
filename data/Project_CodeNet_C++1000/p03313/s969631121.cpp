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
const int MAXN = 3e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

int A[MAXN];
int ans[MAXN];
pii id[MAXN];
char S[MAXN];

void chmin(pii &a,int x)
{
    if(x==-1)return;
    if(a.f==x||a.s==x)return;

    if(a.f==-1){a.f = x; return;}
    else if(A[a.f]<=A[x]){
        a.s = a.f; a.f = x;
        return;
    }
    else {
        if(a.s==-1)a.s = x;
        else if(A[a.s]<A[x])a.s = x;
        return;
    }
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

    for(int i=0;i<(1<<n);i++)
        cin>>A[i];

    id[0] = pii(0,-1);

    for(int i=1;i<(1<<n);i++){
        id[i] = pii(i,-1);
        for(int j=0;j<n;j++){
            if(!((1<<j)&i))continue;
            cur = i^(1<<j);
            chmin(id[i],id[cur].f);
            chmin(id[i],id[cur].s);
            chmin(id[i],(1<<j));
        }
        ans[i] = max(ans[i-1],A[id[i].f]+A[id[i].s]);
    }

    for(int i=1;i<(1<<n);i++)
        cout<<ans[i]<<"\n";

    return 0;
}
