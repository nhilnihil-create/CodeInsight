#include <bits/stdc++.h>
#include <cstdint>
#define pi 3.14159
#define ll long long
// #define int ll
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define tc int t; cin >> t; while(t--)
 
using namespace std;
string repeat(string s, int n) {
    string s1 = "";
    for (int i=0; i<n;i++)
        s1+=s;
    return s1;
}
string getString(char x) {
    string s(1, x);
    return s;
}
 
void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
void  solve(){
  int n;
  cin>>n;
  int a[n+1];
  rep(i,1,n+1) cin>>a[i];
  vector<pair<ll,ll>> dp(n+1,{0,0});
  dp[0].f=0;
  dp[0].s= -1e15;
  rep(i,1,n+1){
    dp[i].f = max(dp[i-1].f+a[i], dp[i-1].s-a[i]);
    dp[i].s = max(dp[i-1].f-a[i], dp[i-1].s+a[i]);
    // cout<<dp[i].f<<" "<<dp[i].s<<endl;
  }
  cout<<dp[n].f<<endl;
}
int main(){
    optimizeIO();
    solve();
}