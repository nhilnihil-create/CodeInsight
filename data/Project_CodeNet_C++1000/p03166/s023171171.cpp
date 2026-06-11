#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define M1 (ll)1000000007
#define M2 (ll)998244353
#define Pi 3.141592653
#define exp 2.71828
#define ll long long
#define ull unsigned long long
#define pi pair<int,int>
#define pl pair<ll,ll> 
#define vi vector<int>
#define vl vector<ll>
#define di deque<int>
#define dl deque<ll>
#define dii deque<pi>
#define dll deque<pl>
#define vvi vector<vi>
#define vvl vector<vl>
#define vii vector<pi>
#define vll vector<pl>
#define pb push_back
#define pp pop_back
#define pf push_front
#define pt pop_front
#define mp make_pair
#define in insert
#define er erase
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define rp(i,a,b) for(int i=a;i<b;i++)
#define rpt(i,a,b,t) for(int i=a;i<b&&t<1;i++)
#define rep(i,n) for(int i = 0 ; i<n ; i++)
#define rept(i,n,t) for(int i = 0 ; i<n&&t<1 ; i++)
#define repr(i,n) for(int i = n-1 ; i>=0 ; i--)
#define reprt(i,n,t) for(int i=n-1;i>=0&&t<1;i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define SORT(v) sort(v.begin(),v.end())
using namespace std;
int dp[100005];
vi graph[100005];
int v[100005]={0};
bool cmp(pair<int,int> i,pair<int,int> j){
    return i.first<j.first;
}
void longest_path(int node){
    if(graph[node].empty()){
        dp[node]=0;
        return;
    }
    for(auto u:graph[node]){
        if(dp[u]==-1) longest_path(u);
        dp[node] = max(dp[node],dp[u]);
    }
    dp[node]+=1;
    // visited
}
int main() {
    fast
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>x>>y;
        graph[x-1].pb(y-1);
    }
    for(int i=0;i<n;++i) dp[i]=-1;
    for(int i=0;i<n;++i){
        if(dp[i]!=-1) continue;
            longest_path(i);
    }
    cout<<*max_element(dp,dp+n);
}
