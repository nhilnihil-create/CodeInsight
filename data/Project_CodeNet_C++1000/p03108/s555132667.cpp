#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ull unsigned long long
#define ld long double

#define mod 1000000007
#define EULER 2.7182818284
#define INF 1000000000

#define pb push_back
#define ins insert
#define IT iterator
#define PQ priority_queue
#define    nl           "\n"
#define fi first
#define se second
#define maxe max_element
#define mine min_element
#define er erase
#define lb lower_bound
#define ub upper_bound

#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mpi map<int,int>
#define mpl map<ll,ll>
#define umpi unordered_map<int,int>
#define umpl unordered_map<ll,ll>
#define si set<int>
#define sl set<ll>
#define msi multi_set<int>
#define msl multi_set<ll>

#define mem(v,i) memset(v,i,sizeof(v)) // v is array. To set all elements to 0 or -1 only. mem(arr,0);


#define repab(i,a,b) for(int i=(a);i<=(b);i++)
#define reprab(i,a,b) for(int i=(a);i>=(b);i--)
#define repll(i,a,b) for(ll i=(a);i<=(b);i++)
#define rep(i,n) for(int i=(0);i<(n);i++)
#define repr(i,n) for(int i=(n);i>=0;i--)
#define bs bitset
#define bpc(a) __builtin_popcount(a)
#define tc int t;cin>>t;while(t--)
template<typename T> void TIME(T start, T end)
{
#ifndef ONLINE_JUDGE
    double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "\nExecuted in: " << fixed
         << time_taken << setprecision(9);
    cout << " sec";
#endif
}

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

ll max(ll a,ll b)
{
    if(a>b)return a;return b;
}
ll min(ll a,ll b)
{
    if(a<b)return a;return b;
}

ll mypow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
//..............................!!!!!!Get ready to fight!!!!!!............................
ll par[100005],r[100005];
ll find(ll a)
{
    if(par[a]<0)
    return a;
    return par[a]=find(par[a]);
}
void merge(ll a,ll b)
{	
	if(r[a]>r[b])
	{
		par[b]=a;
		r[a]+=r[b];
	}
	else
	{
		par[a]=b;
		r[b]+=r[a];
	}
    
}
int main()
{   
     auto start = chrono::high_resolution_clock::now();
    fast
    ll n,m;
    cin>>n>>m;
    ll x,y;
    vector<pi>vec;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        vec.pb({x,y});
    }
    for(int i=1;i<=n;i++){
        par[i]=-1;
        r[i]=1;
    }
    vll ans(m+1);
    ans[m]=n*(n-1)/2;
    for(int i=m-1;i>=0;i--){
        ll a=find(vec[i].fi);
        ll b=find(vec[i].se);
        if(a==b){
            ans[i]=ans[i+1];
        }
        else{
            ll sz1=r[a],sz2=r[b];
            merge(a,b);
            ans[i]=max(ans[i+1]-sz1*sz2,0);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<nl;
    }
    
    auto end = chrono::high_resolution_clock::now();
    TIME(start, end);
    return 0;
}