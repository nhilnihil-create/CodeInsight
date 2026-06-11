#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
vector<vector<ll>> v(100100);
bool used[100100];
ll c[100100];

bool dfs(ll p,ll black){
    used[p]=true;
    bool ret=true;
    if(black){
        if(c[p]==0) c[p]=1;
        else if(c[p]!=1) ret=false;
    }
    else {
        if(c[p]==0) c[p]=2;
        else if(c[p]!=2) ret=false;
    }
    for(auto i:v[p]){
        if(c[i] && c[i]==c[p]) ret=false;
        if(c[i]==0){
            bool res=dfs(i,black^1);
            if(!res) ret=false;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    ll ans = n*(n-1)/2 - m;
    bool pos=dfs(0,1);
    if(!pos){
        cout<<ans<<endl;
    }
    else{
        ans=0;
        ll b=0,w=0;
        for(ll i=0;i<n;i++){
            if(c[i]==1) b++;
            else w++;
        }
        ans = b*w-m;
        cout<<ans<<endl;
    }


 
}