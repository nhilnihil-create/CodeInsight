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
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST ll t;cin>>t;while(t--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
ll sizes[100001];
ll arr[100001];
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
bool prime[10000];
void era(){
    memset(prime,true,sizeof prime);
    for(ll p=2;p*p<=10000;p++){
        if(prime[p]){
            for(ll q=p*p;q<=10000;q+=p){
                prime[q]=false;
            }
        }
    }

    return;
}
ll fac[200001],finv[200001];
ll power(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%MAX;
        b/=2;
        a=(a*a)%MAX;
    }
    return(ans%MAX);
}
ll inverse(ll a){
    return((power(a,MAX-2))%MAX);
}
ll ncr(ll n, ll r){
    ll p1=finv[n-r];
    ll p2=finv[r];

    return((((fac[n]*p1)%MAX)*p2)%MAX);


}
int main(){
    IO

    ll H,W,D;
    cin>>H>>W>>D;
    ll x[H*W+1],y[H*W+1];
    ll z;
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cin>>z;
            y[z]=i;
            x[z]=j;
        }
    }
    ll Q;
    cin>>Q;
    ll cum[H*W+1];
    ll N=H*W;
    memset(cum,0,sizeof cum);
    for(ll i=D+1;i<=N;i++){
        cum[i]=cum[i-D]+abs(x[i]-x[i-D])+abs(y[i]-y[i-D]);
    }

    while(Q--){
        ll L,R;
        cin>>L>>R;
        cout<<cum[R]-cum[L]<<"\n";
    }
    return(0);
}