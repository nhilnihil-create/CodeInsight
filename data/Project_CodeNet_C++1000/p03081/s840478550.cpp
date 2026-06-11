#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define LOR(i,l,r) for (ll i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define LORD(i,r,l) for (ll i=r;i>=l;i--)
#define INF 1000000000
#define CL(x) memset(x,0,sizeof(x))
#define DEB(x) cout << #x << " : " << x << '\n'
#define ALL(x) x.begin(), x.end()
#define SZ(x) x.size()
typedef long long ll;

#define MXN 200005
int N, Q;
int A[MXN];
vector<pii> VQ;

int fall(int qu, int po)
{
    if(qu==Q)return 0;
    if(VQ[qu].f!=A[po])return fall(qu+1, po);
    if(VQ[qu].s==0)
    {
        if(po==1)return -1;
        else return fall(qu+1,po-1);
    }
    else
    {
        if(po==N)return 1;
        else return fall(qu+1,po+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>Q;
    string str;
    cin>>str;
    FOR(i,1,N)A[i]=str[i-1]-'A';
    int ch, di;
    FOR(i,1,Q)
    {
        cin>>str;
        ch = str[0]-'A';
        cin>>str;
        di = (str[0]=='L') ? 0 : 1;
        VQ.pb( mkp(ch, di) );
    }
    int rm, lm;
    int lo, hi;
    lo=0,hi=N+1;
    while(lo+1<hi)
    {
        int md = (lo+hi)/2;
        if( fall(0,md)==-1 )lo=md;
        else hi = md;
    }
    rm = lo;

    lo=0,hi=N+1;
    while(lo+1<hi)
    {
        int md = (lo+hi)/2;
        if( fall(0,md)==1 )hi=md;
        else lo = md;
    }
    lm = hi;

    cout<<N-rm-(N+1-lm)<<'\n';

    return 0;
}

