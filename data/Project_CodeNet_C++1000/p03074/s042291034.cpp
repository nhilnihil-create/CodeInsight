//FIRST THINK THEN CODE.

#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
//#define MOD 998244353
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rrep(i,a,b) for(ll i=a;i>b;--i)
#define FOR(i,n)  for(ll i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define rev(p) reverse(p.begin(),p.end());
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define popcount(x) __builtin_popcountll(x)
#define sz(x) ((ll)x.size())
const ll M=1000000007;
const ll MM=998244353;
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";

 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
  if(a<=0)return 0;
  a%=m;
  if(!b)return 1;
  ll ans=1LL;
  while(b)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }
 
return ans;
}


 
ll poww(ll a,ll b)
{ 
  
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }
 
return ans;

}

template<typename T,typename F>
void chmax( T &a,F b){
  if(b>a)a=b;
}

template<typename T,typename F>
void chmin( T &a,F b){
  if(b<a)a=b;
}


struct segtree{

ll size;

vl sums;

void init(ll n){
  size=n+1;

  sums.resize(2*size,0);
}

void allot(ll n){
  size=1;
  while(size<=n)size*=2;

//vl sums(size,0);

  sums.resize(2*size,0);

}

void build(vl& a,ll x,ll lx,ll rx){
if((rx-lx)==1)
{
 if( lx<sz(a))
  sums[x]=a[lx];

return;
}

ll m=(lx+rx)/2;

/*
   x
  / \
 /   \
2*x+1,2*x+2

*/
build(a,2*x+1,lx,m);  //[lx,m)

build(a,2*x+2,m,rx);  // [m,rx)

sums[x]=sums[2*x+2]+sums[2*x+1];

}

void build(vl& a){
  build(a,0,0,size);
}


void add(ll i,ll v,ll x,ll lx,ll rx){

  if(rx-lx==1){
    sums[x]+=v;
    return;
  }

  ll m=(lx+rx)/2;

if(i<m)add(i,v,2*x+1,lx,m);
else add(i,v,2*x+2,m,rx);

sums[x]=sums[2*x+1]+sums[2*x+2];

}

void add(ll i, ll v){
  add(i,v,0,0,size);
}


void set(ll i,ll v,ll x,ll lx,ll rx){

  if(rx-lx==1){
    sums[x]=v;
    return;
  }

  ll m=(lx+rx)/2;

if(i<m)set(i,v,2*x+1,lx,m);
else set(i,v,2*x+2,m,rx);

sums[x]=sums[2*x+1]+sums[2*x+2];

}

void set(ll i, ll v){
  set(i,v,0,0,size);
}

ll calc(ll l,ll r,ll x,ll lx,ll rx){
  ll tot=0;

if(lx>=r||rx<=l)return 0;
else if(lx>=l&&rx<=r)return sums[x];

ll m=(lx+rx)/2;

return calc(l,r,2*x+1,lx,m)+calc(l,r,2*x+2,m,rx);

}

ll calc(ll l,ll r){
  return calc(l,r,0,0,size);
}

ll find(ll k,ll x,ll lx,ll rx){

if(rx-lx==1)return lx;

ll m=(lx+rx)/2;

if(sums[2*x+1]>=k){
  return find(k,2*x+1,lx,m);
}
else {
  return find(k-sums[2*x+1],2*x+2,m,rx);
}

}

ll find(ll k){
  return find(k,0,0,size);
}


};

const ll N=1e5+5;



ll sp[N];

void sieve(){
  for(int i=1;i<N;i++)sp[i]=i;

    for(int i=2;i<N;i++){
      if(sp[i]==i){
        for(int j=i*i;j<N;j+=i){
          if(sp[j]==j)sp[j]=i;
        }
      }
    }
}

ll vis[N];

//ll colour[N];

vl arr[N];

void dfs(ll node){
  vis[node]=1;

  for(auto child:arr[node]){
    if(!vis[child]){
      dfs(child);
    //  else dfs(child.ff,c);
    }
  }
}

ll g(ll x){
  if(x%4==0)return x;
  if(x%4==1)return 1;
  if(x%4==2)return x+1;
  return 0;
}
  

int main()
{ 

IOS;

ll n,k;

cin>>n>>k;

string s;cin>>s;

vpll x;

ll cnt=0;

if(s[0]=='0')x.pb({0,0});

for(int i=0;i<n;i++){
  if(s[i]=='1'){
    if(!i||s[i-1]=='0'){
      ll d=i;
      while(s[i]=='1')i++;
      x.pb({d,i-1});
    }
  }
}

if(s[n-1]=='0')x.pb({n-1,n-1});

if(k>=sz(x)-1){
  cout<<n;
  return 0;
}

ll ans=0;

for(int i=k;i<sz(x);i++){
chmax(ans,x[i].ss-x[i-k].ff+1);
}

cout<<ans;

//end_routine();

return 0;
 
}
