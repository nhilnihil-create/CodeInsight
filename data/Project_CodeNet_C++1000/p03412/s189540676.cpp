#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 1100000
#define MAX_V 900010
#define vec vector<int>
using namespace std;

ll a[N],b[N],n;
bool check(int k){
    ll int m=1<<(k+1);
    ll int A[N];
    ll int B[N];
    rep(i,n)A[i]=a[i]%m;
    rep(i,n)B[i]=b[i]%m;
    sort(A,A+n);
    int res=0;
    rep(i,n){
        res+=(lower_bound(A,A+n,m-B[i])-lower_bound(A,A+n,m/2-B[i]));
        res+=lower_bound(A,A+n,2*m-B[i])-lower_bound(A,A+n,m*3/2-B[i]);
        res%=2;
    }
    return res;
}
main(){
    cin>>n;
    rep(i,n)scanf("%lld",&a[i]);
    rep(i,n)scanf("%lld",&b[i]);
    ll int r=1;
    ll int ans=0;
    rep(i,31){
        ans+=check(i)*r;
        r<<=1;
    }
    cout<<ans;
}