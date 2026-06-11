#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF (ll)1e18+4
#define md 1000000007
#define mx 10000000
#define mk make_pair
#define __builtin_popcountll(x) one(x)
#define pi pair<int,int>
#define ss second
#define ff first
#define pb emplace_back 
#define all(s) s.begin(),s.end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(x, a) for (auto& x: a)
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define sz(x) ((long long)x.size())
#define mez(s) memset(s,0,sizeof s)
#define mex(s) memset(s,-1,sizeof s)
#define metr(s) memset(s,true, sizeof s)
typedef vector<int> vi; 
typedef vector<ll>vl;
typedef map<int,int> mp;
typedef queue<int> que;
typedef vector<pi> vp;
//const int md=1e9+7;
bool ab[22][22];
void solve(){
	int n;
	cin>>n;
	rep(i,0,n)rep(j,0,n)cin>>ab[i][j];
    vl dp(1<<n);
    dp[0] = 1;
    for(int mask = 0; mask < (1 << n) - 1; ++mask) {
        int a = __builtin_popcount(mask);
        for(int b = 0; b < n; ++b) {
            if(ab[n-1-a][b] && !(mask & (1 << b))) {
                int m2 = mask|(1 << b);
                dp[m2]=(dp[m2]+dp[mask])%md;
            }
        }
    }
	cout<<dp[(1<<n)-1]<<"\n";
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
   int t=1;
   //cin>>t;
     while(t--){
     	solve();
	 }
     return 0;
}
