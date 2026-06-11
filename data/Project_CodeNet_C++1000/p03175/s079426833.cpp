//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define INF 9223372036854777ll
#define pb push_back
using namespace std;
vector<ll> v[100001];
pair<ll,ll> dfs(int s,int pa){
    ll whi=1,so;
    ll sbla=0;
    for(auto i:v[s]){
        if(i!=pa){
            pair<ll,ll> p=dfs(i,s);
            so=whi;
            whi=(whi*p.second);
            whi%=mod;
            sbla=(so * p.first)+(sbla * (p.first+p.second));
            sbla%=mod;
            
        }
    }
    return {whi,(whi+sbla)%mod};//black,white
}
void solve(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    pair<ll,ll> pa=dfs(1,-1);
    cout<<(pa.first+pa.second)%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
