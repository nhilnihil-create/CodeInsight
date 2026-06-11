#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
string alp="abcdefghijklmnopqrstuvwxyz";
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);



int main(){
    ll n;cin>>n;
    ll a[n],b[n];
    ll suma=0,sumb=0;
    rep(i,0,n-1){
        cin>>a[i];
        suma+=a[i];
    }
    rep(i,0,n-1){
        cin>>b[i];
        sumb+=b[i];
    }
    if(sumb>suma){
        cout<<-1<<endl;
        return 0;
    }
    priority_queue<ll> q;
    ll sum=0;
    ll ans=0;
    rep(i,0,n-1){
        if(a[i]<b[i]){
            sum+=(b[i]-a[i]);
            ans++;
        }else if(a[i]>b[i]){
            q.push(a[i]-b[i]);
        }
    }
    while(sum>0){
        ans++;
        sum-=q.top();
        q.pop();
    }
    cout<<ans<<endl;
    
    
    return 0;
}

