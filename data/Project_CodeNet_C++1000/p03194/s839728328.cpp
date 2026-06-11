#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<ll,ll>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

int main(){
sp;

ll n,p;
cin>>n>>p;
if(n==1){
    cout<<p;
    return 0;
}
vector<pi> v;
ll ans=1LL;
ll z=0;
while(p%2==0){
    p>>=1;
    ++z;
}
if(z>=n)v.pb({2LL,z});
for(ll i=3LL; i*i<=p;i+=2){
    if(p%i==0){
        ll z=0;
        while(p%i==0){
            ++z;
            p/=i;
        }
        if(z>=n)
        v.pb({i,z});

    }
}
if(n==1&&p>1)v.pb({p,1LL});
for(auto &it:v)
if(it.s>=n){
    ll temp=it.s/n;
    ll t1=it.f;
    t1=pow(1LL*t1,1LL*temp);
    ans=(1LL*ans*t1);
}
cout<<ans;
return 0;}
