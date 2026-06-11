#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<cmath>
#include<climits>
#include<random>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
const double eps = 1e-6;
 
/////////////////////////////////////////////
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
////////////////////////////////
 
#define int long long

const int N  = 2e5 + 10;

int dp[N];
int a[N];
int h[N];
int stree[N*4];

void update(int idx , int start , int end , int val , int id){

    if(start==end){
        
        stree[idx] = val;
        return;
    }

    int mid = (start + end)/2;

    if(id <= mid && id >= start){

        update(2*idx , start , mid , val , id);
    }
    else{

        update(2*idx + 1 , mid+1 , end , val , id);
    }

    stree[idx] = max(stree[2*idx] , stree[2*idx+1]);
}

int query(int idx , int l , int r, int start , int end){

    if(r < start || end < l){

        return 0;
    }

    if(l <= start && r >= end){

        return stree[idx];
    }

    int mid = (start + end)/2;

    int x = query(2*idx , l , r , start , mid);

    int y = query(2*idx + 1 , l , r , mid + 1 , end);

    return max(x , y);
}

void solve(){

    int n;
    cin>>n;
    for(int i = 0 ; i < n ; ++i)
        cin>>h[i];
    for(int i = 0 ; i < n ; ++i)
        cin>>a[i];

    for(int i = 0 ; i < n ; ++i){

        dp[h[i]] = a[i] + query(1 , 1 , h[i]-1 , 1 , n);

        update(1 , 1 , n , dp[h[i]] , h[i]);

        // for(int j = 1 ; j <= 10 ; ++j)
        //     cout<<stree[j]<<" ";
        // cout<<endl;
    }

    // for(int i = 1 ; i <= n ; ++i){

    //     cout<<i<<" : "<<dp[i]<<endl;
    // }
    int ans = *max_element(dp , dp + n + 1);

    cout<<ans<<endl;

}
 
signed main(){
 
    fast;
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}
