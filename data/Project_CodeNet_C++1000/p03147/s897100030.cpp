//#pragma GCC         optimize("O3")
#include            <bits/stdc++.h>
#include            <ext/pb_ds/assoc_container.hpp>
#include            <ext/pb_ds/tree_policy.hpp>
#define FastIO      ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define pb          push_back
#define mp          make_pair
#define mem(x,i)    memset(x,i,sizeof(x))
#define ff          first
#define ss          second
#define popcount(x) __builtin_popcount(x)
#define all(x)      x.begin(),x.end()
#define Case(t)     for(int ks=1;ks<=t;ks++)
#define fileout     freopen("output.txt","w",stdout)
#define filein      freopen("input.txt","r",stdin)
#define D(x)        cerr<< __LINE__ <<": "<< #x << " = "<<(x) <<'\n';
#define endl        '\n'

using namespace std;
//using namespace __gnu_pbds;

using ll  = long long;
using ld  = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pil = pair<int,ll>;

const int INF    = 0x3f3f3f3f;
const ll LL_INF  = 0x3f3f3f3f3f3f3f3f;
const double PI  = acos(-1);
const double eps = 1e-4;
const int mod    = 1e9+7;
const int mx     = 300005;
/*template <typename T>  using orderedSet =
    tree<T, null_type, less_equal<T>,
    rb_tree_tag, tree_order_statistics_node_update>;//find_by_order,order_of_key*/

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

//ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(; b; b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
/*----------------------BitMask-----------------------------------------*/
//inline int setBit(int N,int pos){return N=N | (1<<pos);}
//inline int resetBit(int N,int pos){return N= N & ~(1<<pos);}
//inline bool checkBit(int N,int pos){return (bool) (N& (1<<pos));}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=0;
    while(1)
    {
        int mux=0;
        for(int i=0;i<n;i++) mux=max(mux,arr[i]);
        if(mux==0) break;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==mux)
            {
                while(i<n && arr[i]==mux)
                {
                    arr[i]--;
                    i++;
                }
                i--;
                cnt++;
            }
        }
        ans+=cnt;
    }
    cout<<ans;
}

