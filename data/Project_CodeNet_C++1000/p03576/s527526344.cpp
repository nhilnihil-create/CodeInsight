#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;
typedef priority_queue< int, vector< int >, greater< int > >  minHeap;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define mod 1000000007
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define bug(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << "\n"

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N = N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

inline int addmod(lli x,lli y)
{
    return (x%mod + y%mod)%mod;
}
inline int submod(lli x,lli y)
{
    return (x%mod - y%mod + mod)%mod;
}
inline int mulmod(lli x,lli y)
{
    return (x%mod * y%mod)%mod;
}

inline int nextSubMask(int i, int mask)
{
    return (i-1)&mask;   /// returns next  submask
}

template<typename T>
void we_r_done(T mssg)
{
    cout<<mssg;
    exit(0);
}


int main()
{
    ///freopen("output.txt","w",stdout);
   // freopen("input.txt","r",stdin);
    FastIO;

    int n,k;
    while(cin>>n>>k){
        vector<pii>v;
        for(int i=1; i<=n; i++){
            int x,y;
            cin>>x>>y;
            v.pb({x,y});
        }
        sort(atoz(v));
        lli ans = 4e18;


        for(int top=0; top<n; top++){
            for(int left=0; left<n; left++){
                for(int bottom=0; bottom<n; bottom++){

                    if(top == bottom) continue;
                    if(v[bottom].se >= v[top].se) continue;
                    if(v[left].fi>v[top].fi || v[left].fi>v[bottom].fi) continue;
                    if(v[left].se>v[top].se || v[left].se<v[bottom].se)  continue;

                    int cnt = 2 , r = max3(v[left].fi+1, v[top].fi, v[bottom].fi);
                    if(top != left && bottom != left) cnt++;

                    for(int i=0; cnt<k && i<n; i++){
                        if(left == i || bottom == i || top == i) continue;
                        if(v[i].fi>v[left].fi && v[i].se>v[bottom].se && v[i].se<v[top].se){
                            cnt++;
                            r = max(r , v[i].fi);
                        }
                    }
                    //if(left == top && v[bottom] == pii(8,1)) cout<<cnt<<" --- "<<r<<endl;
                    if(cnt>=k){
                        //cout<<v[left].fi<<","<<v[left].se<<" ; "<<v[top].se<<endl;
                        ans = min(ans , (r-v[left].fi)*1LL*(v[top].se-v[bottom].se));
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
///using bs = bitset<MX>; // how many distinct number can be form?
///sort(atoz(v), [](const data x, const data y){return (x.a==y.a?x.b>y.b : x.a<y.a);});
