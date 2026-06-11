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
int main() {
    fast
    int h,w;
    cin>>h>>w;
    char grid[h][w];
    for(int i=0;i<h;++i) for(int j=0;j<w;++j) cin>>grid[i][j];
    ll result[h][w];
    int i;
    for(i=0;i<w;++i){
        if(grid[0][i]!='.') break;
        result[0][i] = 1;
    }
    while(i<w) result[0][i]=0,++i;
    for(i=0;i<h;++i){
        if(grid[i][0]!='.') break;
        result[i][0] = 1;
    }
    while(i<h) result[i][0]=0,++i;
    for(int i=1;i<h;++i){
        for(int j=1;j<w;++j){
            result[i][j]=0;
            if(grid[i][j]=='#') continue;
            result[i][j] = ((result[i-1][j]%M1)+(result[i][j-1]%M1))%M1;
        }
    }
    cout<<result[h-1][w-1];
}
