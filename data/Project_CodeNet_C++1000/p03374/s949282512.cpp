#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) (x).begin(),(x).end()
#define F(i,x,n,y) for(i=x;i<n;i+=y)
#define fi(i,x,n) for(i=x;i<n;++i)
#define f(n) for(int i=0;i<n;++i)
#define fr(i,x,n) for(i=x;i>=n;--i)
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int tam=100002;
ll n,C;
ll dis[tam];
ll nut[tam];
ll suf[tam];
ll pre[tam];
pair<ll,int> mx[tam];
pair<ll,int> mx2[tam];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>C;
    ll ans=0;
    ll ans2=0;
    int idx=0;
    f(n){
        cin>>dis[i+1]>>nut[i+1];
        pre[i+1]=pre[i]+nut[i+1]+dis[i]-dis[i+1];
        //cout<<pre[i+1]<<endl;
        if(pre[i+1]>ans){
            ans=pre[i+1];
            idx=i+1;
        }
        mx[i+1]=pair<ll,int>(ans,idx);
        ans2=max(ans2,pre[i+1]);
        //cout<<i+1<<" "<<ans<<" "<<idx<<endl;
        
    }
    dis[n+1]=C;
    int i;
    ans=0;
    idx=0;
    fr(i,n,1){
        suf[i]=suf[i+1]+nut[i]+(C-dis[i+1])-(C-dis[i]);
        if(suf[i]>ans){
            ans=suf[i];
            idx=i;
        }
        ans2=max(ans2,suf[i]);
        mx2[i]=pair<ll,int>(ans,idx);
    }
    fr(i,n,1){
        pair<ll,int> res=mx[i-1];
        ll cost=res.ff+suf[i]-min(dis[res.ss],C-dis[i]);
        ans2=max(ans2,cost);
        //cout<<i<<" "<<res.ff<<" "<<res.ss<<" "<<ans<<endl;
//        cout<<res.ff<<"+ "<<suf[i]<<"-"<<min(dis[res.ss],C-dis[i])<<" "<<cost<<endl;
    }
    fi(i,1,n+1){
        pair<ll,int> res=mx2[i+1];
        ll cost=res.ff+pre[i]-min(C-dis[res.ss],dis[i]);
        ans2=max(ans2,cost);
    }
    cout<<ans2<<endl;
    
    return 0;
}

