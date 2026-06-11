#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace __gnu_pbds;
using namespace std;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int fa[301],sizes[301];
int root(int node){
    while(node!=fa[node]){
        fa[node]=fa[fa[node]];
        node=fa[node];
    }
    return(node);
}
void link(int i,int j){
    i=root(i);j=root(j);
    if(i==j) return;
    if(sizes[i]>sizes[j]) swap(i,j);
    sizes[j]+=sizes[i];
    fa[i]=j;
    return;
}
void solve(){
    int n,cnt=0;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]<=0) cnt++;
        arr[i]=abs(arr[i]);
    }
    sort(arr,arr+n);
    ll sum=0;

    if(cnt%2) sum-=arr[0];
    else sum+=arr[0];
    for(int i=1;i<n;i++){
        sum+=arr[i];
    }
    cout<<sum;
    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
