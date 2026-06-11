#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TEST ll t;cin>>t;while(t--)
ll sizes[100001];
ll arr[100001];

bool ok=true;
ll A[100001];
pll B[100001];

ll root(ll i){
    while(i!=arr[i]) i=arr[i];
    return(i);
}
void Union(ll i,ll j){
    ll root_i=root(i),root_j=root(j);
    if(root_i==root_j) return;
    if(sizes[root_i]>sizes[root_j]) swap(root_i,root_j);
    sizes[root_j]+=sizes[root_i];
    arr[root_i]=arr[root_j];
    return;
}
ll Arr[100001];
bool solve(ll n){
    if(n==1) return(true);
    set<ll> st;
    for(ll i=0;i<n;i++){
        ll m=(Arr[i]+i)%n;
        if(m<0) m+=n;
        if(st.count(m)) return(false);
        st.insert(m);
    }
    return(true);
}
ll power[11];

int main(){
    IO
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    power[0]=1;
    for(ll i=1;i<=k;i++) power[i]=power[i-1]*2;
    ll maxx=-1;
    for(ll i=0;i<=k;i++){
        for(ll j=0;j<=k;j++){
            if(i+j>k) continue;
            ll z=k-(i+j);
            maxx=max(maxx,a*power[i]+b*power[j]+c*power[z]);
        }
    }
    cout<<maxx;
    return(0);
}
