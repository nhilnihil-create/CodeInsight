#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ll  long long 
#define ull unsigned long long int
#define boost ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL)
#define vi vector<int>
#define P push_back
#define F first
#define S second
#define debug(x) cout<<x<<" "
#define pi vector<pair<int,int> >
#define all(a) a.begin(),a.end()
#define int ll
using namespace std;
using namespace __gnu_pbds;
typedef tree <int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll const mod=1e9+7;
int powi(int i,int b){
    int res=1;
    while(b){
        if(b&1)res*=i,res%=mod;
        b>>=1;
        i*=i;
        i%=mod;
    }
    return res;
}
// map<int,int> m;
// ll fact(int n){
// 	//if(n==0)return 0;
// 	if(n<=1)return 1;
// 	if(m[n]!=0)return m[n];
// 	return m[n]=(n*fact(n-1))%mod;
//}
// int ncr(int n,int r){
//     int h=fact(n);
//     int v=fact(r);
//     int j=fact(n-r);
//     v*=j;
//     v%=mod;
//     v=powi(v,mod-2);
//     return (h*v)%mod;
// }
// vi ar(2000000);
// vi sz(2000000);
// int root(int a){
//     if(ar[a]==a)return a;
//     return ar[a]=root(ar[a]);
// }
// int merge(int a,int b){
//     int h=root(a),j=root(b);
//     int ans=sz[h]*sz[j];
//     sz[j]+=sz[h];
//     if(h!=j){
//         ar[h]=j;
//     }
//     return ans;
// } 
void solve(){
    int n;
    cin>>n;
    vi a(1<<(n));
    vector<vi> g((1<<n),vi(2));
    for(int i=0;i<(1<<n);i++){
        cin>>a[i];g[i][0]=i;g[i][1]=-1;
    }
    vi b((1<<n));
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            if((j&(1<<i))){
                if(a[g[j][0]]<a[g[j^(1<<i)][0]]){
                    g[j][1]=g[j][0];
                    g[j][0]=g[j^(1<<i)][0];
                }
                else{
                    if(g[j][0]!=g[j^(1<<i)][0]&&(g[j][1]==-1||(a[g[j][1]]<a[g[j^(1<<i)][0]]))){
                        g[j][1]=g[j^(1<<i)][0];
                    }
                    continue;
                }
                if(g[j^(1<<i)][1]!=-1&&(g[j][1]==-1||a[g[j][1]]<a[g[j^(1<<i)][1]])){
                    g[j][1]=g[j^(1<<i)][1];
                }
            }
        }
    }
    int mex=0;
    for(int i=1;i<(1<<n);i++){
        mex=max(mex,a[g[i][0]]+a[g[i][1]]);
        cout<<mex<<"\n";
    }
    
}   
signed main(){
    boost;
    int t=1;
    //cin>>t;
    for(int _=1;_<=t;_++){
        //cout<<"Case #"<<_<<": ";
        solve();
        cout<<"\n";
    }
    
    return 0;
}