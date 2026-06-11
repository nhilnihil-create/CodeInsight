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
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
////////////////////////////////////////

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    int n,m;cin>>n>>m;
    string s;cin>>s;
    int c[n][2];memset(c,0,sizeof(c));
    vector<int>e[n];
    rep(i,0,m-1){
        int a,b;cin>>a>>b;a--;b--;
        e[a].pb(b);
        e[b].pb(a);
        if(s[a]=='A'){
            c[b][0]++;
        }else{
            c[b][1]++;
        }
        if(s[b]=='A'){
            c[a][0]++;
        }else{
            c[a][1]++;
        }
    }
    bool use[n];memset(use,true,sizeof(use));
    vector<int>que;
    rep(i,0,n-1){
        if(c[i][0]==0||c[i][1]==0){
            que.pb(i);
            use[i]=false;
        }
    }
    for(int b=0;b<que.size();b++){
        int k=0;if(s[que[b]]=='B')k=1;
        for(int x:e[que[b]]){
            c[x][k]--;
            if(c[x][k]==0&&use[x]){
                use[x]=false;
                que.pb(x);
            }
        }
    }
    rep(i,0,n-1){
        if(c[i][0]>0&&c[i][1]>0){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}