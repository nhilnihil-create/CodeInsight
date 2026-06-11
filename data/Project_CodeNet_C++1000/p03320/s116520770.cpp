#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
const double EPS=1E-8;
////////////////////////////////////////

ll calc(ll x){
    ll res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    
    vector<ll>s;
    rep(i,1,9)s.pb(i);
    rep(i,1,999){
        rep(j,1,15){
            ll t=(i+1)*(ll)pow(10,j)-1;
            s.pb(t);
        }
    }
    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    int n=s.size();
    double t[n];
    rep(i,0,n-1){
        t[i]=(double)s[i]/(double)calc(s[i]);
    }
    bool a[n];memset(a,true,sizeof(a));
    for(int i=0;i<=n-1;i++){
        for(int j=i+1;j<=n-1;j++){
            if(t[j]<t[i])a[i]=false;
        }
    }
    vector<ll>ans;
    rep(i,0,n-1){
        if(a[i])ans.pb(s[i]);
    }
    int k;cin>>k;
    rep(i,0,k-1)cout<<ans[i]<<endl;
    
    return 0;
}