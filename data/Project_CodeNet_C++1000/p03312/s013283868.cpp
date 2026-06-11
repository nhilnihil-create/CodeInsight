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
ll psum[MAXN];
char S[MAXN];

int main()
{
    int n,m,k,a,b,c,x,y,q;
    int sum = 0;
    int cnt = 0;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
        psum[i] = psum[i-1]+(ll)A[i];
    }
    a = 1;
    c = 3;
    ll mn,mx;
    ll res = psum[n];

    for(b=2;b<n-1;b++){

        while(psum[a]<psum[b]-psum[a]&&a<b)a++;
        while(psum[c]-psum[b]<psum[n]-psum[c]&&c<n)c++;
        for(int j=0;j<4;j++){
            mn = psum[n]; mx = 0;
            x = ((j&2)>>1); y = (j&1);
            mn = min(psum[b]-psum[a-x],psum[a-x]);
            mx = max(psum[b]-psum[a-x],psum[a-x]);
            mn = min(mn,min(psum[n]-psum[c-y],psum[c-y]-psum[b]));
            mx = max(mx,max(psum[n]-psum[c-y],psum[c-y]-psum[b]));
            res = min(res,mx-mn);
        }

    }

    cout<<res<<"\n";

    return 0;
}
