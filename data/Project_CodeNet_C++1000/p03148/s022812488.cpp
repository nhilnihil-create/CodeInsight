#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a7=1000000007;
ll inf=1000000000000000;
typedef pair<ll,ll> l_l;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back


ll min(ll a,ll b){
    if(a<b)return a;
    return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    return b;
}

bool used[100010];
bool usedt[100010];
ll maxi[100010];

int main(){
    ll n,k;cin>>n>>k;
    ll t[n],d[n];
    vector<l_l> p;
    vector<vector<ll>> v(100010);
    
    rep(i,0,n-1){
        cin>>t[i]>>d[i];
        p.pb(make_pair(d[i],t[i]));
        v[t[i]].pb(d[i]);
    }
    sort(p.begin(),p.end(),greater<l_l>());
    ll ans=0;
    ll sum=0;
    ll c=0;
    vector<ll> out;
    vector<l_l> in;
    rep(i,0,k-1){
        ans+=p[i].first;
        used[i]=true;
        if(usedt[p[i].second]==false){
            usedt[p[i].second]=true;
            c++;
            maxi[p[i].second]=p[i].first;
        }else{
            if(maxi[p[i].second]>p[i].first){
                out.pb(p[i].first);
            }else{
                out.pb(maxi[p[i].second]);
                maxi[p[i].second]=p[i].first;
            }
        }
    }
    ans=ans+c*c;
    sum=ans;
    rep(i,1,n){
        if(usedt[i]==false){
            if(v[i].size()!=0){
                rep(j,0,v[i].size()-1){
                    in.pb(make_pair(v[i][j],i));
                }
            }
        }
    }
    sort(out.begin(),out.end());
    sort(in.begin(),in.end(),greater<l_l>());
    ll j=0;
    bool b;
    sum=ans;
    
    if(in.size()!=0 && out.size()!=0){
    
    rep(i,0,out.size()-1){
        
        
        b=true;
        sum=sum-out[i];
        while(b){
            if(usedt[in[j].second]){
                j++;
                if(j>=in.size()){
                    break;
                }
            }else{
                sum=sum+in[j].first;
                usedt[in[j].second]=true;
                sum=sum-c*c;
                j++;
                c++;
                sum=sum+c*c;
                ans=max(sum,ans);
                if(j>=in.size()){
                    break;
                }
                b=false;
            }
        }
        if(b){
            break;
        }
    }
        
    }
    cout<<ans<<endl;
    
    return 0;
}


