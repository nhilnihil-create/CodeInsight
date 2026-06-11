#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pqb             priority_queue<ll>
#define pqs             priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            ll x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mx 3000
ll n,m;
bool dp[100005];
vector<ll>v;

string solve(ll k){
   for(int i=1;i<=k;i++){
    for(ll move: v){
        if(move>i)
            continue;
        if(dp[i-move]==0){//cout<<"i "<<i<<" move "<<move<<"  "<<i-move<<"  dp i "<<i<<"  "<<1<<endl;
                dp[i]=1;}
    }
   }
   return dp[k]?"First":"Second";
}
int main()
{
    FIO;
    ll c,d,e,f=0,sum=0,ck,k,p,q,r,t,add=0,w,x,y,z;
    string ans;
    cin>>n>>k;
    memset(dp,0,sizeof dp);
//vector<ll>v(n);
for(int i=0;i<n;i++){
        cin>>p;
        v.pb(p);
    }

/*
     for(int i=0;i<n;i++){
        cout<<i<<" "<<v[i];
   }*/
    ans=solve(k);
    cout<<ans<<endl;
v.clear();
    return 0;
}
