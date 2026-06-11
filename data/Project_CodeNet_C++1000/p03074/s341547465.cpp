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
    ll N,K;
    cin>>N>>K;
    string s;
    cin>>s;
    vector<int> v,w;
    int cnt0=0,cnt1=0;
    if(s[0]=='0') cnt0++;
    else cnt1++;
    for(int i=1;i<N;i++){
        if(s[i]=='0'){
            if(cnt0==0){
                v.push_back(cnt1);
                cnt1=0;
                w.push_back(1);
            }
            cnt0++;
        }
        else{
            if(cnt1==0){
                v.push_back(cnt0);
                cnt0=0;
                w.push_back(0);
            }
            cnt1++;
        }

    }
    if(cnt1) {v.push_back(cnt1);w.push_back(1);}
    if(cnt0) {v.push_back(cnt0);w.push_back(0);}
    /*
    for(auto x:v) cout<<x<<" ";
    cout<<endl;
    */
    int m=v.size();
    int dp[m+1];
    dp[0]=0;
    for(int i=0;i<m;i++)
        dp[i+1]=dp[i]+v[i];

    int maxx=0;
    for(int i=0;i<m;i++){
        int k=K*2;
        if(w[i]) k++;
        maxx=max(maxx,dp[min(m,i+k)]-dp[i]);
    }
    cout<<maxx;
    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
